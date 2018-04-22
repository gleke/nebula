#!/usr/bin/python
#-*- coding: utf-8 -*-
#encoding=utf-8

'''
/*
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
'''

import glob, re, binascii, os, sys


def txt_wrap_by(start_str, end, line):
  start = line.find(start_str)
  if start >= 0:
    start += len(start_str)
  end = line.find(end, start)
  if end >= 0:
    return line[start:end].strip()

input_file = ''
output_path = ''
next_output_path = False
for arg in sys.argv[1:]:
  if next_output_path:
    next_output_path = False
    output_path = arg
  elif arg == '-o':
    next_output_path = True
  elif re.match(r'^-o(.+)', arg):
    output_path = arg[2:]
  else:
    input_file = arg

if input_file == '':
  print('Input file required.')
  sys.exit(1)
if output_path == '':
  print('Output path required.')
  sys.exit(1)

output_header = output_path + '/schema.tl.h'
output_source = output_path + '/schema.tl.cc'

# define some checked flag conversions
# the key flag type should be a subset of the value flag type
# with exact the same names, then the key flag can be implicitly
# casted to the value flag type
parentFlags = {};
parentFlagsList = [];
def addChildParentFlags(child, parent):
  parentFlagsList.append(child);
  parentFlags[child] = parent;
addChildParentFlags('MTPDmessageService', 'MTPDmessage');
addChildParentFlags('MTPDupdateShortMessage', 'MTPDmessage');
addChildParentFlags('MTPDupdateShortChatMessage', 'MTPDmessage');
addChildParentFlags('MTPDupdateShortSentMessage', 'MTPDmessage');
addChildParentFlags('MTPDreplyKeyboardHide', 'MTPDreplyKeyboardMarkup');
addChildParentFlags('MTPDreplyKeyboardForceReply', 'MTPDreplyKeyboardMarkup');
addChildParentFlags('MTPDinputPeerNotifySettings', 'MTPDpeerNotifySettings');
addChildParentFlags('MTPDpeerNotifySettings', 'MTPDinputPeerNotifySettings');
addChildParentFlags('MTPDchannelForbidden', 'MTPDchannel');

# this is a map (key flags -> map (flag name -> flag bit))
# each key flag of parentFlags should be a subset of the value flag here
parentFlagsCheck = {};

layer = '';
funcs = 0
types = 0;
consts = 0
funcsNow = 0
enums = [];

funcsDict = {};
FuncsDict = {};
funcsList = [];

typesDict = {};
TypesDict = {};
typesList = [];
TypesList = [];

boxed = {};
funcsText = '';
typesText = '';
dataTexts = '';
creatorProxyText = '';
inlineMethods = '';
textSerializeInit = '';
textSerializeMethods = '';
forwards = '';
forwTypedefs = '';

classTypesTexts = '';
resClassTypesTexts = '';
classFuncsTexts = '';
registers = [];

with open(input_file) as f:
  for line in f:
    line=line.strip('\n')
    layerline = re.match(r'// LAYER (\d+)', line)
    if (layerline):
      # 当前层
      layer = 'constexpr int CURRENT_LAYER = ' + layerline.group(1) + ';';

    nocomment = re.match(r'^(.*?)//', line)
    if (nocomment):
      line = nocomment.group(1);
    if (re.match(r'\-\-\-functions\-\-\-', line)):
      funcsNow = 1;
      continue;
    if (re.match(r'\-\-\-types\-\-\-', line)):
      funcsNow = 0;
      continue;
    if (re.match(r'^\s*$', line)):
      continue;

    nametype = re.match(r'([a-zA-Z\.0-9_]+)#([0-9a-f]+)([^=]*)=\s*([a-zA-Z\.<>0-9_]+);', line);
    if (not nametype):
      # 特殊处理 vector#1cb5c415 {t:Type} # [ t ] = Vector t;
      if (not re.match(r'vector#1cb5c415 \{t:Type\} # \[ t \] = Vector t;', line)):
        print('Bad line found: ' + line);
      continue;

    # resPQ#05162463 nonce:int128 server_nonce:int128 pq:string server_public_key_fingerprints:Vector<long> = ResPQ;
    # name为: resPQ
    # contest.saveDeveloperInfo#9a5f6e95 vk_id:int name:string phone_number:string age:int city:string = Bool;
    # name为: contest_saveDeveloperInfo
    name = nametype.group(1);
    nameInd = name.find('.');
    if (nameInd >= 0):
      Name = name[0:nameInd] + '_' + name[nameInd + 1:nameInd + 2].upper() + name[nameInd + 2:];
      name = name.replace('.', '_');
    else:
      Name = name[0:1].upper() + name[1:];

    # typeid为: 05162463
    typeid = nametype.group(2);
    # 去掉前面的0
    while (len(typeid) > 0 and typeid[0] == '0'):
      typeid = typeid[1:];
    if (len(typeid) == 0):
      typeid = '0';
    typeid = '0x' + typeid;

    cleanline = nametype.group(1) + nametype.group(3) + '= ' + nametype.group(4);
    cleanline = re.sub(r' [a-zA-Z0-9_]+\:flags\.[0-9]+\?true', '', cleanline);
    cleanline = cleanline.replace('<', ' ').replace('>', ' ').replace('  ', ' ');
    cleanline = re.sub(r'^ ', '', cleanline);
    cleanline = re.sub(r' $', '', cleanline);
    cleanline = cleanline.replace(':bytes ', ':string ');
    cleanline = cleanline.replace('?bytes ', '?string ');
    cleanline = cleanline.replace('{', '');
    cleanline = cleanline.replace('}', '');

    # 通过cleanline计算出typeid并进行验证
    countTypeId = binascii.crc32(binascii.a2b_qp(cleanline));
    if (countTypeId < 0):
      countTypeId += 2 ** 32;
    countTypeId = '0x' + re.sub(r'^0x|L$', '', hex(countTypeId));
    if (typeid != countTypeId):
      print('Warning: counted ' + countTypeId + ' mismatch with provided ' + typeid + ' (' + cleanline + ')');
      continue;

    # params为: nonce:int128 server_nonce:int128 pq:string server_public_key_fingerprints:Vector<long>
    params = nametype.group(3);
    # restype为: ResPQ
    restype = nametype.group(4);
    if (restype.find('<') >= 0):
      # vector
      templ = re.match(r'^([vV]ector<)([A-Za-z0-9\._]+)>$', restype);
      if (templ):
        vectemplate = templ.group(2);
        if (re.match(r'^[A-Z]', vectemplate) or re.match(r'^[a-zA-Z0-9]+_[A-Z]', vectemplate)):
          # restype = templ.group(1) + 'MTP' + vectemplate.replace('.', '_') + '>';
          # restype = 'std::vector<std::shared_ptr<' + vectemplate.replace('.', '_') + '>>';
          restype = templ.group(1) + vectemplate.replace('.', '_') + '>';
          # print('name: ' + name + ', object: ' + restype);
        elif (vectemplate == 'int' or vectemplate == 'long' or vectemplate == 'string'):
          if (vectemplate == 'int'):
            vectemplate = 'int32_t';
          elif (vectemplate == 'long'):
            vectemplate = 'int64_t';
          else:
            vectemplate = 'std::string';
          # restype = templ.group(1) + 'MTP' + vectemplate.replace('.', '_') + '>';
          # restype = 'std::vector<' + vectemplate.replace('.', '_') + '>';
          restype = templ.group(1) + vectemplate.replace('.', '_') + '>';
          # print('name: ' + name + ', int/long/string: ' + restype);
        else:
          foundmeta = '';
          for metatype in typesDict:
            for typedata in typesDict[metatype]:
              if (typedata[0] == vectemplate):
                foundmeta = metatype;
                break;
            if (len(foundmeta) > 0):
              break;
          if (len(foundmeta) > 0):
            # ptype = templ.group(1) + 'MTP' + foundmeta.replace('.', '_') + '>';
            ptype = templ.group(1) + foundmeta.replace('.', '_') + '>';
            # print('name: ' + name + ', foundmeta: ' + ptype);
          else:
            print('Bad vector param: ' + vectemplate);
            continue;
      else:
        print('Bad template type: ' + restype);
        continue;

    resType = restype.replace('.', '_');
    # print('restype: ' + restype + ', resType: ' + resType);

    if (restype.find('.') >= 0):
      parts = re.match(r'([a-z]+)\.([A-Z][A-Za-z0-9<>\._]+)', restype)
      if (parts):
        restype = parts.group(1) + '_' + parts.group(2)[0:1].lower() + parts.group(2)[1:];
      else:
        print('Bad result type name with dot: ' + restype);
        continue;
    else:
      if (re.match(r'^[A-Z]', restype)):
        restype = restype[:1].lower() + restype[1:];
      else:
        print('Bad result type name: ' + restype);
        continue;

    # print('name: %s, typeid: %s, params: %s, resType: %s, restype: %s' %(name, typeid, params, resType, restype));

    boxed[resType] = restype;
    boxed[Name] = name;
    enums.append('\tmtpc_' + name + ' = ' + typeid);

    # 生成: REGISTER_TLOBJECT(TL_resPQ);
    registers.append('REGISTER_TLOBJECT(TL_' + name + ');\n');

    # 参数处理
    paramsList = params.strip().split(' ');
    prms = {};
    conditions = {}; # 条件: flags:# first_name:flags.0?string last_name:flags.1?string about:flags.2?string
    trivialConditions = {}; # true type, allow_flashcall:flags.0?true
    prmsList = [];
    conditionsList = [];
    isTemplate = hasFlags = hasTemplate = '';
    for param in paramsList:
      if (re.match(r'^\s*$', param)):
        continue;
      templ = re.match(r'^{([A-Za-z]+):Type}$', param); # vector#1cb5c415 {t:Type} # [ t ] = Vector t;
      if (templ):
        hasTemplate = templ.group(1);
        # print('hasTemplate: ' + hasTemplate + ', in: ' + cleanline);
        continue;

      pnametype = re.match(r'([a-z_][a-z0-9_]*):([A-Za-z0-9<>\._]+|![a-zA-Z]+|\#|[a-z_][a-z0-9_]*\.[0-9]+\?[A-Za-z0-9<>\._]+)$', param);
      if (not pnametype):
        print('Bad param found: "' + param + '" in line: ' + line);
        continue;

      pname = pnametype.group(1); # 参数名
      ptypewide = pnametype.group(2); # 参数类型

      if (re.match(r'^!([a-zA-Z]+)$', ptypewide)):
        if ('!' + hasTemplate == ptypewide):
          # 模板类型
          isTemplate = pname;
          ptype = 'TQueryType';
          # print('template param name: ' + pname + ', type: TQueryType');
        else:
          print('Bad template param name: "' + param + '" in line: ' + line);
          continue;
      elif (ptypewide == '#'):
        # flags, 类似protobuf的optional字段
        hasFlags = pname;
        # if funcsNow:
        #   ptype = 'flags<MTP' + name + '::Flags>';
        # else:
        #   ptype = 'flags<MTPD' + name + '::Flags>';

        ptype = 'int32_t';

      else:
        ptype = ptypewide;
        if (ptype.find('?') >= 0):
          # flags.0?string
          pmasktype = re.match(r'([a-z_][a-z0-9_]*)\.([0-9]+)\?([A-Za-z0-9<>\._]+)', ptype);
          if (not pmasktype or pmasktype.group(1) != hasFlags):
            print('Bad param found: "' + param + '" in line: ' + line);
            continue;
          ptype = pmasktype.group(3);
          if (ptype.find('<') >= 0):
            # inputMediaUploadedPhoto#630c9af1 flags:# file:InputFile caption:string stickers:flags.0?Vector<InputDocument> = InputMedia;
            # print('flags\'s template type: ' + ptype);
            templ = re.match(r'^([vV]ector<)([A-Za-z0-9\._]+)>$', ptype);
            if (templ):
              vectemplate = templ.group(2);
              if (re.match(r'^[A-Z]', vectemplate) or re.match(r'^[a-zA-Z0-9]+_[A-Z]', vectemplate)):
                # ptype = templ.group(1) + 'MTP' + vectemplate.replace('.', '_') + '>';
                # ptype = 'std::vector<std::shared_ptr<' + vectemplate.replace('.', '_') + '>>';
                ptype = 'TLObjectVector<' + vectemplate.replace('.', '_') + '>';

              elif (vectemplate == 'int' or vectemplate == 'long' or vectemplate == 'string'):
                # ptype = templ.group(1) + 'MTP' + vectemplate.replace('.', '_') + '>';

                if (vectemplate == 'int'):
                  ptype = 'TLInt32Vector';

                  # vectemplate = 'int32_t';
                elif (vectemplate == 'long'):
                  ptype = 'TLInt64Vector';

                  # vectemplate = 'int64_t';
                else:
                  ptype = 'TLStringVector';

                  # vectemplate = 'std::string';

                # ptype = 'std::vector<' + vectemplate.replace('.', '_') + '>';

              else:
                foundmeta = '';
                for metatype in typesDict:
                  for typedata in typesDict[metatype]:
                    if (typedata[0] == vectemplate):
                      foundmeta = metatype;
                      break;
                  if (len(foundmeta) > 0):
                    break;
                if (len(foundmeta) > 0):
                  # ptype = templ.group(1) + 'MTP' + foundmeta.replace('.', '_') + '>';
                  ptype = 'std::vector<' + foundmeta.replace('.', '_') + '>';
                  print('foundmeta: ' + ptype);
                else:
                  print('Bad vector param: ' + vectemplate);
                  continue;
            else:
              print('Bad template type: ' + ptype);
              continue;
          if (not pname in conditions):
            conditionsList.append(pname);
            conditions[pname] = pmasktype.group(2);
            # print('condition: ' + pname + ' --> ' + pmasktype.group(2) + ', ' + ptype);
            if (ptype == 'true'):
              trivialConditions[pname] = 1;
        elif (ptype.find('<') >= 0):
          templ = re.match(r'^([vV]ector<)([A-Za-z0-9\._]+)>$', ptype);
          if (templ):
            vectemplate = templ.group(2);
            if (re.match(r'^[A-Z]', vectemplate) or re.match(r'^[a-zA-Z0-9]+_[A-Z]', vectemplate)):
              # ptype = templ.group(1) + 'MTP' + vectemplate.replace('.', '_') + '>';
              # ptype = 'std::vector<std::shared_ptr<' + vectemplate.replace('.', '_') + '>>';
              ptype = 'TLObjectVector<' + vectemplate.replace('.', '_') + '>';

            elif (vectemplate == 'int' or vectemplate == 'long' or vectemplate == 'string'):
              # ptype = templ.group(1) + 'MTP' + vectemplate.replace('.', '_') + '>';
              if (vectemplate == 'int'):
                ptype = 'TLInt32Vector';

                # vectemplate = 'int32_t';
              elif (vectemplate == 'long'):
                ptype = 'TLInt64Vector';
                # vectemplate = 'int64_t';
              else:
                ptype = 'TLStringVector';
                # vectemplate = 'std::string';
              # ptype = 'std::vector<' + vectemplate.replace('.', '_') + '>';

            else:
              foundmeta = '';
              for metatype in typesDict:
                for typedata in typesDict[metatype]:
                  if (typedata[0] == vectemplate):
                    foundmeta = metatype;
                    break;
                if (len(foundmeta) > 0):
                  break;
              if (len(foundmeta) > 0):
                # ptype = templ.group(1) + 'MTP' + foundmeta.replace('.', '_') + '>';
                ptype = 'std::vector<TL_' + vectemplate + '*>';
                print('ptype: ' + ptype + ', metatype: ' + metatype + ', vectemplate: ' + vectemplate);
              else:
                print('Bad vector param: ' + vectemplate);
                continue;
          else:
            print('Bad template type: ' + ptype);
            continue;
      prmsList.append(pname);
      # prms[pname] = ptype.replace('.', '_');

      ptype2 = ptype.replace('.', '_');
      if (ptype2 == 'true'):
        ptype2 = 'bool';
      if (ptype2 == 'int'):
        ptype2 = 'int32_t';
      if (ptype2 == 'long'):
        ptype2 = 'int64_t';
      if (ptype2 == 'int128'):
        ptype2 = 'TLInt128';
      if (ptype2 == 'int256'):
        ptype2 = 'TLInt256';
      if (ptype2 == 'string'):
        ptype2 = 'std::string';
      if (ptype2 == 'bytes'):
        ptype2 = 'std::string';

      prms[pname] = ptype2;

    # print(prms);

    if (isTemplate == '' and resType == 'X'):
      print('Bad response type "X" in "' + name +'" in line: ' + line);
      continue;

    if funcsNow:
      if (isTemplate != ''):
        funcsText += '\ntemplate <typename TQueryType>';
      funcsText += '\nclass MTP' + name + ' { // RPC method \'' + nametype.group(1) + '\'\n'; # class

      funcsText += 'public:\n';

      prmsStr = [];
      prmsInit = [];
      prmsNames = [];
      if (hasFlags != ''):
        funcsText += '\tenum class Flag : int32 {\n';
        maxbit = 0;
        parentFlagsCheck['MTP' + name] = {};
        for paramName in conditionsList:
          funcsText += '\t\tf_' + paramName + ' = (1 << ' + conditions[paramName] + '),\n';
          parentFlagsCheck['MTP' + name][paramName] = conditions[paramName];
          maxbit = max(maxbit, int(conditions[paramName]));
        if (maxbit > 0):
          funcsText += '\n';
        funcsText += '\t\tMAX_FIELD = (1 << ' + str(maxbit) + '),\n';
        funcsText += '\t};\n';
        funcsText += '\tQ_DECLARE_FLAGS(Flags, Flag);\n';
        funcsText += '\tfriend inline Flags operator~(Flag v) { return QFlag(~static_cast<int32>(v)); }\n';
        funcsText += '\n';
        if (len(conditions)):
          for paramName in conditionsList:
            if (paramName in trivialConditions):
              funcsText += '\tbool is_' + paramName + '() const { return v' + hasFlags + '.v & Flag::f_' + paramName + '; }\n';
            else:
              funcsText += '\tbool has_' + paramName + '() const { return v' + hasFlags + '.v & Flag::f_' + paramName + '; }\n';
          funcsText += '\n';

      if (len(prms) > len(trivialConditions)):
        for paramName in prmsList:
          if (paramName in trivialConditions):
            continue;
          paramType = prms[paramName];
          prmsInit.append('v' + paramName + '(_' + paramName + ')');
          prmsNames.append('_' + paramName);
          if (paramName == isTemplate):
            ptypeFull = paramType;
          else:
            ptypeFull = 'MTP' + paramType;
          funcsText += '\t' + ptypeFull + ' v' + paramName + ';\n';
          if (paramType in ['int', 'Int', 'bool', 'Bool', 'flags<Flags>']):
            prmsStr.append(ptypeFull + ' _' + paramName);
          else:
            prmsStr.append('const ' + ptypeFull + ' &_' + paramName);
        funcsText += '\n';

      funcsText += '\tMTP' + name + '() = default;\n'; # constructor
      if (len(prms) > len(trivialConditions)):
        funcsText += '\tMTP' + name + '(' + ', '.join(prmsStr) + ') : ' + ', '.join(prmsInit) + ' {\n\t}\n';

      funcsText += '\n';
      funcsText += '\tuint32 innerLength() const {\n'; # count size
      size = [];
      for k in prmsList:
        v = prms[k];
        if (k in conditionsList):
          if (not k in trivialConditions):
            size.append('(has_' + k + '() ? v' + k + '.innerLength() : 0)');
        else:
          size.append('v' + k + '.innerLength()');
      if (not len(size)):
        size.append('0');
      funcsText += '\t\treturn ' + ' + '.join(size) + ';\n';
      funcsText += '\t}\n';

      funcsText += '\tmtpTypeId type() const {\n\t\treturn mtpc_' + name + ';\n\t}\n'; # type id

      funcsText += '\tvoid read(const mtpPrime *&from, const mtpPrime *end, mtpTypeId cons = mtpc_' + name + ') {\n'; # read method
      for k in prmsList:
        v = prms[k];
        if (k in conditionsList):
          if (not k in trivialConditions):
            funcsText += '\t\tif (has_' + k + '()) { v' + k + '.read(from, end); } else { v' + k + ' = MTP' + v + '(); }\n';
        else:
          funcsText += '\t\tv' + k + '.read(from, end);\n';
      funcsText += '\t}\n';

      funcsText += '\tvoid write(mtpBuffer &to) const {\n'; # write method
      for k in prmsList:
        v = prms[k];
        if (k in conditionsList):
          if (not k in trivialConditions):
            funcsText += '\t\tif (has_' + k + '()) v' + k + '.write(to);\n';
        else:
          funcsText += '\t\tv' + k + '.write(to);\n';
      funcsText += '\t}\n';

      if (isTemplate != ''):
        funcsText += '\n\tusing ResponseType = typename TQueryType::ResponseType;\n';
      else:
        funcsText += '\n\tusing ResponseType = MTP' + resType + ';\n'; # method return type

      funcsText += '};\n'; # class ending
      if (len(conditionsList)):
        funcsText += 'Q_DECLARE_OPERATORS_FOR_FLAGS(MTP' + name + '::Flags)\n\n';
      if (isTemplate != ''):
        funcsText += 'template <typename TQueryType>\n';
        funcsText += 'class MTP' + Name + ' : public MTPBoxed<MTP' + name + '<TQueryType> > {\n';
        funcsText += 'public:\n';
        funcsText += '\tMTP' + Name + '() = default;\n';
        funcsText += '\tMTP' + Name + '(const MTP' + name + '<TQueryType> &v) : MTPBoxed<MTP' + name + '<TQueryType> >(v) {\n\t}\n';
        if (len(prms) > len(trivialConditions)):
          funcsText += '\tMTP' + Name + '(' + ', '.join(prmsStr) + ') : MTPBoxed<MTP' + name + '<TQueryType> >(MTP' + name + '<TQueryType>(' + ', '.join(prmsNames) + ')) {\n\t}\n';
        funcsText += '};\n';
      else:
        funcsText += 'class MTP' + Name + ' : public MTPBoxed<MTP' + name + '> {\n';
        funcsText += 'public:\n';
        funcsText += '\tMTP' + Name + '() = default;\n';
        funcsText += '\tMTP' + Name + '(const MTP' + name + ' &v) : MTPBoxed<MTP' + name + '>(v) {\n\t}\n';
        if (len(prms) > len(trivialConditions)):
          funcsText += '\tMTP' + Name + '(' + ', '.join(prmsStr) + ') : MTPBoxed<MTP' + name + '>(MTP' + name + '(' + ', '.join(prmsNames) + ')) {\n\t}\n';
        funcsText += '};\n';
      funcs = funcs + 1;

      if (not restype in funcsDict):
        funcsList.append(restype);
        funcsDict[restype] = [];
        # TypesDict[restype] = resType;
      FuncsDict[restype] = resType;
      funcsDict[restype].append([name, typeid, prmsList, prms, hasFlags, conditionsList, conditions, trivialConditions, line]);

      # print(funcsDict[restype])

    else:
      if (isTemplate != ''):
        print('Template types not allowed: "' + resType + '" in line: ' + line);
        continue;
      if (not restype in typesDict):
        typesList.append(restype);
        TypesList.append(resType);

        # print('typeList added: ' + restype);
        typesDict[restype] = [];
      TypesDict[restype] = resType;
      typesDict[restype].append([name, typeid, prmsList, prms, hasFlags, conditionsList, conditions, trivialConditions, line]);

      consts = consts + 1;

      # print(TypesDict[restype])

for restype in typesList:
  v = typesDict[restype];
  resType = TypesDict[restype];

  # print('restype:' + restype + ', resType: ' + resType);

  withData = 0;
  creatorsText = '';
  constructsText = '';
  constructsInline = '';

  # forwards += 'class MTP' + restype + ';\n';
  if (restype.find('<') < 0):
    forwards += 'class ' + resType + ';\n';


  forwTypedefs += 'using MTP' + resType + ' = MTPBoxed<MTP' + restype + '>;\n';

  withType = (len(v) > 1);
  switchLines = '';
  friendDecl = '';
  getters = '';
  reader = '';
  writer = '';
  sizeList = [];
  sizeFast = '';
  newFast = '';
  sizeCases = '';
#  print(v)

  resClassTypesTexts += 'class ' + resType + ' : public TLObject {\n'; # type class declaration
  resClassTypesTexts += 'public:\n';
  resClassTypesTexts += '  virtual ~' + resType + '() override = default;\n';
  resClassTypesTexts += '};\n\n';

  for data in v:
    name = data[0];
    typeid = data[1];
    prmsList = data[2];
    prms = data[3];
    hasFlags = data[4];
    conditionsList = data[5];
    conditions = data[6];
    trivialConditions = data[7];
    line = data[8]

    forwards += 'class TL_' + name + ';\n';

    dataText = '';
    dataText += '\nclass MTPD' + name + ' : public MTP::internal::TypeData {\n'; # data class
    dataText += 'public:\n';

    classTypesTexts += '// ' + line + '\n';
    classTypesTexts += 'class TL_' + name + ' : public ' + resType + ' {\n'; # type class declaration
    classTypesTexts += 'public:\n';
    classTypesTexts += '  enum {\n';
    classTypesTexts += '    CLASS_ID = ' + typeid + '\n';
    classTypesTexts += '  };\n\n';

    classTypesTexts += '  ~TL_' + name + '() override {} \n\n';
    classTypesTexts += '  uint32_t GetClassID() const override {\n';
    classTypesTexts += '    return CLASS_ID;\n';
    classTypesTexts += '  }\n\n';

    classTypesTexts += '  std::string ToString() const override {\n';
    classTypesTexts += '    return "' + name + '#' + typeid + '";\n';
    classTypesTexts += '  }\n\n';

    # if ((flags & 1) != 0) {
    classTypesTexts += '  //////////////////////////////////////////////////////////////////////////////\n';
    for paramName in prmsList:
      paramType = prms[paramName];

      if (paramName in trivialConditions):
        classTypesTexts += '  bool is_' + paramName + '() const { return flags_ & (1 << ' + conditions[paramName] + '); }\n';
        classTypesTexts += '  void set_' + paramName + '() { flags_ |= (1 << ' + conditions[paramName] + '); }\n';
        classTypesTexts += '  void clear_' + paramName + '() { flags_ &= ~(1 << ' + conditions[paramName] + '); }\n\n';
        continue;

      if (paramName in conditionsList):
        classTypesTexts += '  bool has_' + paramName + '() const { return flags_ & (1 << ' + conditions[paramName] + '); }\n';

      if (paramType in TypesList):
        classTypesTexts += '  const ' + paramType + '* ' + paramName + '() const { return ' + paramName + '_.get(); } \n';
        classTypesTexts += '  template <class T>\n';
        classTypesTexts += '  typename std::enable_if<std::is_base_of<' + paramType + ', T>::value, T>::type* mutable_' + paramName + '() {\n';
        classTypesTexts += '    if (!' + paramName + '_) ' + paramName + '_ = std::make_unique<T>(); \n';
        if (paramName in conditionsList):
          classTypesTexts += '    flags_ |= (1 << ' + conditions[paramName] + ');\n';
        classTypesTexts += '    return  dynamic_cast<T*>(' + paramName + '_.get());\n';
        classTypesTexts += '  }\n';
        if (paramName in conditionsList):
          classTypesTexts += '  void set_' + paramName + '(std::unique_ptr<' + paramType + '> v) {\n';
          classTypesTexts += '    flags_ |= (1 << ' + conditions[paramName] + ');\n';
          classTypesTexts += '    ' + paramName + '_ = std::move(v);\n';
          classTypesTexts += '  }\n\n';
        else:
          classTypesTexts += '  void set_' + paramName + '(std::unique_ptr<' + paramType + '> v) { ' + paramName + '_ = std::move(v); }\n\n';
      else:
        if (paramName == 'flags'):
          continue;

        cTexts = '';
        if (paramName in conditionsList):
          cTexts = 'flags_ |= (1 << ' + conditions[paramName] + ');\n    ';

        if (paramType in ['int32_t', 'int64_t', 'double']):
          if (paramName == 'long'):
            classTypesTexts += '  ' + paramType + ' _' + paramName + '() const { return ' + paramName + '_; } \n';
          else:
            classTypesTexts += '  ' + paramType + ' ' + paramName + '() const { return ' + paramName + '_; } \n';          
          classTypesTexts += '  void set_' + paramName + '(' + paramType + ' v) {\n    ' + cTexts + paramName + '_ = v; \n  }\n\n';
        elif (paramType == 'std::string'):
          classTypesTexts += '  std::string* mutable_' + paramName + '() { return &' + paramName + '_; } \n';
          classTypesTexts += '  const std::string& ' + paramName + '() const { return ' + paramName + '_; } \n';
          classTypesTexts += '  void set_' + paramName + '(const std::string& v) {\n    ' + cTexts + paramName + '_ = v; \n  } \n';
          classTypesTexts += '  void set_' + paramName + '(const char* v, size_t n) {\n    ' + cTexts + paramName + '_.assign(v, n);\n  }\n';
          classTypesTexts += '  void set_' + paramName + '(const char* v) {\n    ' + cTexts + paramName + '_ = v;\n  }\n\n';
        elif (paramType in ['TLInt128', 'TLInt256', 'TLInt512', 'TLInt1024', 'TLInt2048']):
          classTypesTexts += '  ' + paramType + '* mutable_' + paramName + '() { return &' + paramName + '_; } \n';
          classTypesTexts += '  const ' + paramType + '& ' + paramName + '() const { return ' + paramName + '_; } \n';
          classTypesTexts += '  void set_' + paramName + '(const ' + paramType + '& v) { ' + paramName + '_.Copy(v); }\n\n';
        elif (paramType in ['TLInt32Vector', 'TLInt64Vector', 'TLStringVector']):
          classTypesTexts += '  size_t ' + paramName + '_size() const { return ' + paramName + '_.size(); } \n';
          classTypesTexts += '  const ' + paramType + '& ' + paramName + '() const { return ' + paramName + '_; } \n';
          if (paramType == 'TLInt32Vector'):
            classTypesTexts += '  int32_t ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx]; } \n';
            classTypesTexts += '  void add_' + paramName + '(int32_t v) {\n    ' + cTexts + paramName + '_.mutable_vector()->push_back(v);\n  }\n';
          elif (paramType == 'TLInt64Vector'):
            classTypesTexts += '  int64_t ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx]; } \n';
            classTypesTexts += '  void add_' + paramName + '(int64_t v) {\n    ' + cTexts + paramName + '_.mutable_vector()->push_back(v);\n  }\n';
          else:
            classTypesTexts += '  const std::string& ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx]; } \n';
            classTypesTexts += '  void add_' + paramName + '(const std::string& v) {\n    ' + cTexts + paramName + '_.mutable_vector()->push_back(v);\n  }\n';
        elif (paramType.find('std::vector') >= 0):
          classTypesTexts += '  size_t ' + paramName + '_size() const { return ' + paramName + '_.size(); } \n';
          eptype = txt_wrap_by('<', '*', paramType);
          classTypesTexts += '  const ' + eptype + '* ' + paramName + '(int idx) const { return ' + paramName + '_[idx].get(); } \n';
          classTypesTexts += '  template <class T>\n';
          classTypesTexts += '  typename std::enable_if<std::is_base_of<' + eptype + ', T>::value, T>::type* add_' + paramName + '() {\n';
          classTypesTexts += '    auto v = new T();\n';
          classTypesTexts += '    ' + cTexts + paramName + '_.push_back(std::unique_ptr<T>(v));\n';
          classTypesTexts += '    return v;\n';
          classTypesTexts += '  };\n';
          classTypesTexts += '  void add_' + paramName + '(std::unique_ptr<' + eptype + '> v) {\n    ' + cTexts + paramName + '_.push_back(std::move(v));\n  };\n\n';
        elif (paramType.find('TLObjectVector') >= 0):
          eptype = txt_wrap_by('<', '>', paramType);
          classTypesTexts += '  size_t ' + paramName + '_size() const { return ' + paramName + '_.size(); } \n';
          classTypesTexts += '  const ' + eptype + '* ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx].get(); } \n';
          classTypesTexts += '  template <class T>\n';
          classTypesTexts += '  typename std::enable_if<std::is_base_of<' + eptype + ', T>::value, T>::type* add_' + paramName + '() {\n';
          classTypesTexts += '    auto v = new T();\n';
          classTypesTexts += '    ' + cTexts + paramName + '_.mutable_vector()->push_back(std::unique_ptr<T>(v));\n';
          classTypesTexts += '    return v;\n';
          classTypesTexts += '  };\n';
          classTypesTexts += '  void add_' + paramName + '(std::unique_ptr<' + eptype + '> v) {\n   ' + cTexts +paramName + '_.mutable_vector()->push_back(std::move(v)); };\n\n';
        else:
          classTypesTexts += '';

    classTypesTexts += 'protected:\n';
    classTypesTexts += '  bool Decode(IOBufReader& iobr) override;\n';
    classTypesTexts += '  bool Encode(IOBufWriter& iobw) const override;\n\n';

    classTypesTexts += 'private:\n';

    # if (hasFlags):
    #   classTypesTexts += '  int flags_ {0};\n\n';

    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramName == 'flags'):
        classTypesTexts += '  uint32_t flags_ {0};\n';
      elif (paramType == 'bool'):
        classTypesTexts += '';
      #   classTypesTexts += '  bool ' + paramName + '_ {false};\n';
      elif (paramType in ['int32_t', 'int64_t', 'double']):
        classTypesTexts += '  ' +  paramType + ' ' + paramName + '_ {0};\n';
      elif (paramType in TypesList):
        classTypesTexts += '  std::unique_ptr<' + paramType + '> ' + paramName + '_;\n';
      elif (paramType.find('std::vector') >= 0):
        eptype = txt_wrap_by('<', '*', paramType);
        classTypesTexts += '  std::vector<std::unique_ptr<' + eptype + '>> ' + paramName + '_;\n';
      elif (paramType.find('TLObjectVector') >= 0):
        eptype = txt_wrap_by('<', '>', paramType);
        classTypesTexts += '  TLObjectVector<' + eptype + '> ' + paramName + '_;\n';
      else:
        classTypesTexts += '  ' + paramType + ' ' + paramName + '_;\n';

    classTypesTexts += '};\n\n';

    # cc实现
    classFuncsTexts += '//////////////////////////////////////////////////////////////////////////////\n';
    classFuncsTexts += '// ' + name + '\n';
    classFuncsTexts += 'bool TL_' + name + '::Decode(IOBufReader& iobr) {\n';
    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramType in TypesList):
        if (paramName in conditionsList):
          classFuncsTexts += '  if (has_' + paramName + '()) {\n';
          classFuncsTexts += '    auto o = TLObject::CreateObjectByIOBuf(iobr);\n';
          classFuncsTexts += '    if (o == nullptr) return false;\n';
          classFuncsTexts += '    auto o2 = reinterpret_cast<' + paramType + '*>(o);\n';
          classFuncsTexts += '    if (o2 == nullptr) {\n';
          classFuncsTexts += '      delete o;\n';
          classFuncsTexts += '      return false;\n';
          classFuncsTexts += '    }\n';
          classFuncsTexts += '    ' + paramName + '_ = std::unique_ptr<' + paramType + '>(o2);\n';
          classFuncsTexts += '  }\n';
        else:
          classFuncsTexts += '  if (true) {\n';
          classFuncsTexts += '    auto o = TLObject::CreateObjectByIOBuf(iobr);\n';
          classFuncsTexts += '    if (o == nullptr) return false;\n';
          classFuncsTexts += '    auto o2 = reinterpret_cast<' + paramType + '*>(o);\n';
          classFuncsTexts += '    if (o2 == nullptr) {\n';
          classFuncsTexts += '      delete o;\n';
          classFuncsTexts += '      return false;\n';
          classFuncsTexts += '    }\n';
          classFuncsTexts += '    ' + paramName + '_ = std::unique_ptr<' + paramType + '>(o2);\n';
          classFuncsTexts += '  }\n';
      else:
        if (paramType in ['int32_t', 'int64_t', 'double']):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) {\n';
            classFuncsTexts += '    ' + paramName + '_ = iobr.readLE<' + paramType + '>();\n  }\n';
          else:
            classFuncsTexts += '  ' + paramName + '_ = iobr.readLE<' + paramType + '>();\n';
        elif (paramType == 'std::string'):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) {\n';
            classFuncsTexts += '    ReadString(iobr, &' + paramName + '_);\n  }\n';
          else:
            classFuncsTexts += '  ReadString(iobr, &' + paramName + '_);\n';
        elif (paramType in ['TLInt128', 'TLInt256', 'TLInt512', 'TLInt1024', 'TLInt2048']):
          classFuncsTexts += '  ReadTLIntN(iobr, &' + paramName + '_);\n';
        elif (paramType in ['TLInt32Vector', 'TLInt64Vector', 'TLStringVector'] or paramType.find('TLObjectVector') >= 0):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) {\n';
            classFuncsTexts += '    ' + paramName + '_.ParseFromIOBuf(iobr, true);\n  }\n';
          else:
            classFuncsTexts += '  ' + paramName + '_.ParseFromIOBuf(iobr, true);\n';
        elif (paramType.find('std::vector') >= 0):
          eptype = txt_wrap_by('<', '*', paramType);
          classFuncsTexts += '  auto sz = iobr.readLE<uint32_t>();\n';
          classFuncsTexts += '  for (uint32_t i=0; i<sz; ++i) {\n';
          classFuncsTexts += '    auto o = TLObject::CreateObjectByIOBuf(iobr);\n';
          classFuncsTexts += '    if (o->GetClassID() != ' + eptype + '::CLASS_ID) {\n';
          classFuncsTexts += '      delete o;\n';
          classFuncsTexts += '      return false;\n';
          classFuncsTexts += '    }\n';
          classFuncsTexts += '    ' + paramName + '_.push_back(std::unique_ptr<' + eptype + '>(reinterpret_cast<' + eptype + '*>(o)));\n';
          classFuncsTexts += '  }\n';
        else:
          classFuncsTexts += '';

    classFuncsTexts += '  return true;\n';
    classFuncsTexts += '}\n';

    classFuncsTexts += 'bool TL_' + name + '::Encode(IOBufWriter& iobw) const {\n';
    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramType in TypesList):
        if (paramName in conditionsList):
          classFuncsTexts += '  if (has_' + paramName + '()) ' + paramName + '_->SerializeToIOBuf(iobw);\n';
        else:
          classFuncsTexts += '  if (!' + paramName + '_) return false;\n';
          classFuncsTexts += '  ' + paramName + '_-> SerializeToIOBuf(iobw);\n';
      else:
        if (paramType in ['int32_t', 'int64_t', 'double']):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) iobw.writeLE(' + paramName + '_);\n';
          else:
            classFuncsTexts += '  iobw.writeLE(' + paramName + '_);\n';
        elif (paramType == 'std::string'):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) WriteString(iobw, ' + paramName + '_);\n';
          else:
            classFuncsTexts += '  WriteString(iobw, ' + paramName + '_);\n';
        elif (paramType in ['TLInt128', 'TLInt256', 'TLInt512', 'TLInt1024', 'TLInt2048']):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) WriteTLIntN(iobw, ' + paramName + '_);\n';
          else:
            classFuncsTexts += '  WriteTLIntN(iobw, ' + paramName + '_);\n';
        elif (paramType in ['TLInt32Vector', 'TLInt64Vector', 'TLStringVector'] or paramType.find('TLObjectVector') >= 0):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) ' + paramName + '_.SerializeToIOBuf(iobw);\n';
          else:
            classFuncsTexts += '  ' + paramName + '_.SerializeToIOBuf(iobw);\n';
        elif (paramType.find('std::vector') >= 0):
          classFuncsTexts += '  iobw.writeLE(' + paramName + '_.size());\n'
          classFuncsTexts += '  for (size_t i=0; i<' + paramName + '_.size(); ++i) {\n';
          classFuncsTexts += '    ' + paramName + '_[i]->SerializeToIOBuf(iobw);\n;'
          classFuncsTexts += '  }\n';
        else:
          classFuncsTexts += '';
    classFuncsTexts += '  return true;\n';
    classFuncsTexts += '}\n\n';

    sizeList = [];
    creatorParams = [];
    creatorParamsList = [];
    readText = '';
    writeText = '';

    if (hasFlags != ''):
      dataText += '\tenum class Flag : int32 {\n';
      maxbit = 0;
      parentFlagsCheck['MTPD' + name] = {};
      for paramName in conditionsList:
        dataText += '\t\tf_' + paramName + ' = (1 << ' + conditions[paramName] + '),\n';
        parentFlagsCheck['MTPD' + name][paramName] = conditions[paramName];
        maxbit = max(maxbit, int(conditions[paramName]));
      if (maxbit > 0):
        dataText += '\n';
      dataText += '\t\tMAX_FIELD = (1 << ' + str(maxbit) + '),\n';
      dataText += '\t};\n';
      dataText += '\tQ_DECLARE_FLAGS(Flags, Flag);\n';
      dataText += '\tfriend inline Flags operator~(Flag v) { return QFlag(~static_cast<int32>(v)); }\n';
      dataText += '\n';
      if (len(conditions)):
        for paramName in conditionsList:
          if (paramName in trivialConditions):
            dataText += '\tbool is_' + paramName + '() const { return v' + hasFlags + '.v & Flag::f_' + paramName + '; }\n';
          else:
            dataText += '\tbool has_' + paramName + '() const { return v' + hasFlags + '.v & Flag::f_' + paramName + '; }\n';
        dataText += '\n';

    dataText += '\tMTPD' + name + '() = default;\n'; # default constructor
    switchLines += '\t\tcase mtpc_' + name + ': '; # for by-type-id type constructor
    if (len(prms) > len(trivialConditions)):
      switchLines += 'setData(new MTPD' + name + '()); ';
      withData = 1;

      getters += '\tconst MTPD' + name + ' &c_' + name + '() const;\n'; # const getter
      constructsInline += 'inline const MTPD' + name + ' &MTP' + restype + '::c_' + name + '() const {\n';
      if (withType):
        constructsInline += '\tt_assert(_type == mtpc_' + name + ');\n';
      constructsInline += '\treturn queryData<MTPD' + name + '>();\n';
      constructsInline += '}\n';

      constructsText += '\texplicit MTP' + restype + '(const MTPD' + name + ' *data);\n'; # by-data type constructor
      constructsInline += 'inline MTP' + restype + '::MTP' + restype + '(const MTPD' + name + ' *data) : TypeDataOwner(data)';
      if (withType):
        constructsInline += ', _type(mtpc_' + name + ')';
      constructsInline += ' {\n}\n';

      dataText += '\tMTPD' + name + '('; # params constructor
      prmsStr = [];
      prmsInit = [];
      for paramName in prmsList:
        if (paramName in trivialConditions):
          continue;
        paramType = prms[paramName];

        if (paramType in ['int', 'Int', 'bool', 'Bool']):
          prmsStr.append('MTP' + paramType + ' _' + paramName);
          creatorParams.append('MTP' + paramType + ' _' + paramName);
        else:
          prmsStr.append('const MTP' + paramType + ' &_' + paramName);
          creatorParams.append('const MTP' + paramType + ' &_' + paramName);
        creatorParamsList.append('_' + paramName);
        prmsInit.append('v' + paramName + '(_' + paramName + ')');
        if (withType):
          readText += '\t\t';
          writeText += '\t\t';
        if (paramName in conditions):
          readText += '\tif (v->has_' + paramName + '()) { v->v' + paramName + '.read(from, end); } else { v->v' + paramName + ' = MTP' + paramType + '(); }\n';
          writeText += '\tif (v.has_' + paramName + '()) v.v' + paramName + '.write(to);\n';
          sizeList.append('(v.has_' + paramName + '() ? v.v' + paramName + '.innerLength() : 0)');
        else:
          readText += '\tv->v' + paramName + '.read(from, end);\n';
          writeText += '\tv.v' + paramName + '.write(to);\n';
          sizeList.append('v.v' + paramName + '.innerLength()');

      # forwards += 'class MTPD' + name + ';\n'; # data class forward declaration

      dataText += ', '.join(prmsStr) + ') : ' + ', '.join(prmsInit) + ' {\n\t}\n';

      dataText += '\n';
      for paramName in prmsList: # fields declaration
        if (paramName in trivialConditions):
          continue;
        paramType = prms[paramName];
        dataText += '\tMTP' + paramType + ' v' + paramName + ';\n';
      sizeCases += '\t\tcase mtpc_' + name + ': {\n';
      sizeCases += '\t\t\tconst MTPD' + name + ' &v(c_' + name + '());\n';
      sizeCases += '\t\t\treturn ' + ' + '.join(sizeList) + ';\n';
      sizeCases += '\t\t}\n';
      sizeFast = '\tconst MTPD' + name + ' &v(c_' + name + '());\n\treturn ' + ' + '.join(sizeList) + ';\n';
      newFast = 'new MTPD' + name + '()';
    else:
      sizeFast = '\treturn 0;\n';

    switchLines += 'break;\n';
    dataText += '};\n'; # class ending

    if (len(prms) > len(trivialConditions)):
      dataTexts += dataText; # add data class

    if (not friendDecl):
      friendDecl += '\tfriend class MTP::internal::TypeCreator;\n';
    creatorProxyText += '\tinline static MTP' + restype + ' new_' + name + '(' + ', '.join(creatorParams) + ') {\n';
    if (len(prms) > len(trivialConditions)): # creator with params
      creatorProxyText += '\t\treturn MTP' + restype + '(new MTPD' + name + '(' + ', '.join(creatorParamsList) + '));\n';
    else:
      if (withType): # creator by type
        creatorProxyText += '\t\treturn MTP' + restype + '(mtpc_' + name + ');\n';
      else: # single creator
        creatorProxyText += '\t\treturn MTP' + restype + '();\n';
    creatorProxyText += '\t}\n';
    if (len(conditionsList)):
      creatorsText += 'Q_DECLARE_OPERATORS_FOR_FLAGS(MTPD' + name + '::Flags)\n';
    creatorsText += 'inline MTP' + restype + ' MTP_' + name + '(' + ', '.join(creatorParams) + ') {\n';
    creatorsText += '\treturn MTP::internal::TypeCreator::new_' + name + '(' + ', '.join(creatorParamsList) + ');\n';
    creatorsText += '}\n';

    if (withType):
      reader += '\t\tcase mtpc_' + name + ': _type = cons; '; # read switch line
      if (len(prms) > len(trivialConditions)):
        reader += '{\n';
        reader += '\t\t\tauto v = new MTPD' + name + '();\n';
        reader += '\t\t\tsetData(v);\n';
        reader += readText;
        reader += '\t\t} break;\n';

        writer += '\t\tcase mtpc_' + name + ': {\n'; # write switch line
        writer += '\t\t\tauto &v = c_' + name + '();\n';
        writer += writeText;
        writer += '\t\t} break;\n';
      else:
        reader += 'break;\n';
    else:
      if (len(prms) > len(trivialConditions)):
        reader += '\n\tauto v = new MTPD' + name + '();\n';
        reader += '\tsetData(v);\n';
        reader += readText;

        writer += '\tauto &v = c_' + name + '();\n';
        writer += writeText;

  forwards += '\n';

  typesText += '\nclass MTP' + restype; # type class declaration
  if (withData):
    typesText += ' : private MTP::internal::TypeDataOwner'; # if has data fields
  typesText += ' {\n';
  typesText += 'public:\n';
  typesText += '\tMTP' + restype + '()'; # default constructor
  inits = [];
  if not (withType):
    if (withData):
      inits.append('TypeDataOwner(' + newFast + ')');
  if (withData and not withType):
    typesText += ';\n';
    inlineMethods += '\ninline MTP' + restype + '::MTP' + restype + '()';
    if (inits):
      inlineMethods += ' : ' + ', '.join(inits);
    inlineMethods += ' {\n}\n';
  else:
    if (inits):
      typesText += ' : ' + ', '.join(inits);
    typesText += ' {\n\t}\n';

  if (withData):
    typesText += getters;

  typesText += '\n\tuint32 innerLength() const;\n'; # size method
  inlineMethods += '\ninline uint32 MTP' + restype + '::innerLength() const {\n';
  if (withType and sizeCases):
    inlineMethods += '\tswitch (_type) {\n';
    inlineMethods += sizeCases;
    inlineMethods += '\t}\n';
    inlineMethods += '\treturn 0;\n';
  else:
    inlineMethods += sizeFast;
  inlineMethods += '}\n';

  typesText += '\tmtpTypeId type() const;\n'; # type id method
  inlineMethods += 'inline mtpTypeId MTP' + restype + '::type() const {\n';
  if (withType):
    inlineMethods += '\tt_assert(_type != 0);\n';
    inlineMethods += '\treturn _type;\n';
  else:
    inlineMethods += '\treturn mtpc_' + v[0][0] + ';\n';
  inlineMethods += '}\n';

  typesText += '\tvoid read(const mtpPrime *&from, const mtpPrime *end, mtpTypeId cons'; # read method
  if (not withType):
    typesText += ' = mtpc_' + name;
  typesText += ');\n';
  inlineMethods += 'inline void MTP' + restype + '::read(const mtpPrime *&from, const mtpPrime *end, mtpTypeId cons) {\n';
  if (withData):
    if not (withType):
      inlineMethods += '\tif (cons != mtpc_' + v[0][0] + ') throw mtpErrorUnexpected(cons, "MTP' + restype + '");\n';
  if (withType):
    inlineMethods += '\tswitch (cons) {\n'
    inlineMethods += reader;
    inlineMethods += '\t\tdefault: throw mtpErrorUnexpected(cons, "MTP' + restype + '");\n';
    inlineMethods += '\t}\n';
  else:
    inlineMethods += reader;
  inlineMethods += '}\n';

  typesText += '\tvoid write(mtpBuffer &to) const;\n'; # write method
  inlineMethods += 'inline void MTP' + restype + '::write(mtpBuffer &to) const {\n';
  if (withType and writer != ''):
    inlineMethods += '\tswitch (_type) {\n';
    inlineMethods += writer;
    inlineMethods += '\t}\n';
  else:
    inlineMethods += writer;
  inlineMethods += '}\n';

  typesText += '\n\tusing ResponseType = void;\n'; # no response types declared

  typesText += '\nprivate:\n'; # private constructors
  if (withType): # by-type-id constructor
    typesText += '\texplicit MTP' + restype + '(mtpTypeId type);\n';
    inlineMethods += 'inline MTP' + restype + '::MTP' + restype + '(mtpTypeId type) : ';
    inlineMethods += '_type(type)';
    inlineMethods += ' {\n';
    inlineMethods += '\tswitch (type) {\n'; # type id check
    inlineMethods += switchLines;
    inlineMethods += '\t\tdefault: throw mtpErrorBadTypeId(type, "MTP' + restype + '");\n\t}\n';
    inlineMethods += '}\n'; # by-type-id constructor end

  if (withData):
    typesText += constructsText;
    inlineMethods += constructsInline;

  if (friendDecl):
    typesText += '\n' + friendDecl;

  if (withType):
    typesText += '\n\tmtpTypeId _type = 0;\n'; # type field var

  typesText += '};\n'; # type class ended

  inlineMethods += creatorsText;
  typesText += 'using MTP' + resType + ' = MTPBoxed<MTP' + restype + '>;\n'; # boxed type definition

for childName in parentFlagsList:
  parentName = parentFlags[childName];
  for flag in parentFlagsCheck[childName]:
    if (not flag in parentFlagsCheck[parentName]):
      print('Flag ' + flag + ' not found in ' + parentName + ' which should be a flags-parent of ' + childName);
      error
    elif (parentFlagsCheck[childName][flag] != parentFlagsCheck[parentName][flag]):
      print('Flag ' + flag + ' has different value in ' + parentName + ' which should be a flags-parent of ' + childName);
      error
  inlineMethods += 'inline ' + parentName + '::Flags mtpCastFlags(' + childName + '::Flags flags) { return ' + parentName + '::Flags(QFlag(flags)); }\n';
  inlineMethods += 'inline ' + parentName + '::Flags mtpCastFlags(MTPflags<' + childName + '::Flags> flags) { return mtpCastFlags(flags.v); }\n';

classTypesTexts += '\n// RPC\n';
for restype in funcsList:
  v = funcsDict[restype];
  for data in v:
    name = data[0];
    typeid = data[1];
    prmsList = data[2];
    prms = data[3];
    hasFlags = data[4];
    conditionsList = data[5];
    conditions = data[6];
    trivialConditions = data[7];
    line = data[8]

    classTypesTexts += '// ' + line + '\n'; # type class declaration

    classTypesTexts += 'class TL_' + name + ' : public TLObject {\n'; # type class declaration
    classTypesTexts += 'public:\n';
    classTypesTexts += '  enum {\n';
    classTypesTexts += '    CLASS_ID = ' + typeid + '\n';
    classTypesTexts += '  };\n\n';

    classTypesTexts += '  uint32_t GetClassID() const override {\n';
    classTypesTexts += '    return CLASS_ID;\n';
    classTypesTexts += '  }\n\n';

    classTypesTexts += '  std::string ToString() const override {\n';
    classTypesTexts += '    return "' + name + '#' + typeid + '";\n';
    classTypesTexts += '  }\n\n';

    classTypesTexts += '  //////////////////////////////////////////////////////////////////////////////\n';
    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramName in trivialConditions):
        classTypesTexts += '  bool is_' + paramName + '() const { return flags_ & (1 << ' + conditions[paramName] + '); }\n';
        classTypesTexts += '  void set_' + paramName + '() { flags_ |= (1 << ' + conditions[paramName] + '); }\n';
        classTypesTexts += '  void clear_' + paramName + '() { flags_ &= ~(1 << ' + conditions[paramName] + '); }\n\n';
        continue;

      if (paramName in conditionsList):
        classTypesTexts += '  bool has_' + paramName + '() const { return flags_ & (1 << ' + conditions[paramName] + '); }\n';

      cTexts = '';
      if (paramName in conditionsList):
        cTexts = 'flags_ |= (1 << ' + conditions[paramName] + ');\n    ';

      if (paramType in TypesList):
        classTypesTexts += '  const ' + paramType + '* ' + paramName + '() const { return ' + paramName + '_.get(); } \n';
        classTypesTexts += '  template <class T>\n';
        classTypesTexts += '  typename std::enable_if<std::is_base_of<' + paramType + ', T>::value, T>::type* mutable_' + paramName + '() {\n';
        classTypesTexts += '    if (!' + paramName + '_) ' + paramName + '_ = std::make_unique<T>(); \n';
        classTypesTexts += '    ' + cTexts + 'return  dynamic_cast<T*>(' + paramName + '_.get());\n';
        classTypesTexts += '  }\n';
        classTypesTexts += '  void set_' + paramName + '(std::unique_ptr<' + paramType + '> v) {\n    ' + cTexts + paramName + '_ = std::move(v);\n  }\n\n';
      else:
        if (paramName == 'flags'):
          classTypesTexts += '';
        elif (paramType == 'TQueryType'):
          classTypesTexts += '  // template <class T>\n';
          classTypesTexts += '  const TLObject* ' + paramName + '() const { return ' + paramName + '_.get(); } \n';
          classTypesTexts += '  void set_' + paramName + '(std::unique_ptr<TLObject> v) { ' + paramName + '_ = std::move(v); }\n\n';
        if (paramType in ['int32_t', 'int64_t', 'double']):
          if (paramName == 'long'):
            classTypesTexts += '  ' + paramType + ' _' + paramName + '() const { return ' + paramName + '_; } \n';
          else:
            classTypesTexts += '  ' + paramType + ' ' + paramName + '() const { return ' + paramName + '_; } \n';          
          classTypesTexts += '  void set_' + paramName + '(' + paramType + ' v) {\n    ' + cTexts + paramName + '_ = v;\n  }\n\n';
        elif (paramType == 'std::string'):
          classTypesTexts += '  std::string* mutable_' + paramName + '() { return &' + paramName + '_; } \n';
          classTypesTexts += '  const std::string& ' + paramName + '() const { return ' + paramName + '_; } \n';
          classTypesTexts += '  void set_' + paramName + '(const std::string& v) {\n    ' + cTexts + paramName + '_ = v;\n  }\n';
          classTypesTexts += '  void set_' + paramName + '(const char* v, size_t n) {\n    ' + paramName + '_.assign(v, n);\n  }\n';
          classTypesTexts += '  void set_' + paramName + '(const char* v) {\n    ' + cTexts + paramName + '_ = v;\n  }\n\n';
        elif (paramType in ['TLInt128', 'TLInt256', 'TLInt512', 'TLInt1024', 'TLInt2048']):
          classTypesTexts += '  ' + paramType + '* mutable_' + paramName + '() { return &' + paramName + '_; } \n';
          classTypesTexts += '  const ' + paramType + '& ' + paramName + '() const { return ' + paramName + '_; } \n';
          classTypesTexts += '  void set_' + paramName + '(const ' + paramType + '& v) { ' + paramName + '_.Copy(v); } \n\n';
        elif (paramType in ['TLInt32Vector', 'TLInt64Vector', 'TLStringVector']):
          classTypesTexts += '  size_t ' + paramName + '_size() const { return ' + paramName + '_.size(); } \n';
          classTypesTexts += '  const ' + paramType + '& ' + paramName + '() const { return ' + paramName + '_; } \n';
          if (paramType == 'TLInt32Vector'):
            classTypesTexts += '  int32_t ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx]; } \n';
            classTypesTexts += '  void add_' + paramName + '(int32_t v) {\n    ' + cTexts + paramName + '_.mutable_vector()->push_back(v);\n  }\n';
          elif (paramType == 'TLInt64Vector'):
            classTypesTexts += '  int64_t ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx]; } \n';
            classTypesTexts += '  void add_' + paramName + '(int64_t v) {\n    ' + paramName + '_.mutable_vector()->push_back(v);\n  }\n';
          else:
            classTypesTexts += '  const std::string& ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx]; } \n';
            classTypesTexts += '  void add_' + paramName + '(const std::string& v) {\n    ' + paramName + '_.mutable_vector()->push_back(v);\n  }\n';
          classTypesTexts += '  ' + paramType + '* mutable_' + paramName + '() { return &' + paramName + '_; } \n\n';
        elif (paramType.find('std::vector') >= 0):
          classTypesTexts += '  size_t ' + paramName + '_size() const { return ' + paramName + '_.size(); } \n';
          eptype = txt_wrap_by('<', '*', paramType);
          classTypesTexts += '  const ' + eptype + '* ' + paramName + '(int idx) const { return ' + paramName + '_[idx].get(); } \n';
          classTypesTexts += '  template <class T>\n';
          classTypesTexts += '  typename std::enable_if<std::is_base_of<' + eptype + ', T>::value, T>::type* add_' + paramName + '() {\n';
          classTypesTexts += '    auto v = new T();\n';
          classTypesTexts += '    ' + cTexts + paramName + '_.push_back(std::unique_ptr<T>(v));\n';
          classTypesTexts += '    return v;\n';
          classTypesTexts += '  };\n';
          classTypesTexts += '  void add_' + paramName + '(std::unique_ptr<' + eptype + '> v) {\n    ' + cTexts + paramName + '_.push_back(std::move(v));\n  };\n\n';
        elif (paramType.find('TLObjectVector') >= 0):
          eptype = txt_wrap_by('<', '>', paramType);
          classTypesTexts += '  size_t ' + paramName + '_size() const { return ' + paramName + '_.size(); } \n';
          classTypesTexts += '  const ' + eptype + '* ' + paramName + '(int idx) const { return ' + paramName + '_.vector()[idx].get(); } \n';
          classTypesTexts += '  template <class T>\n';
          classTypesTexts += '  typename std::enable_if<std::is_base_of<' + eptype + ', T>::value, T>::type* add_' + paramName + '() {\n';
          classTypesTexts += '    auto v = new T();\n';
          classTypesTexts += '    ' + cTexts + paramName + '_.mutable_vector()->push_back(std::unique_ptr<T>(v));\n';
          classTypesTexts += '    return v;\n';
          classTypesTexts += '  };\n';
          classTypesTexts += '  void add_' + paramName + '(std::unique_ptr<' + eptype + '> v) {\n    ' + cTexts + paramName + '_.mutable_vector()->push_back(std::move(v));\n  };\n\n';
        else:
          classTypesTexts += '';

    classTypesTexts += 'protected:\n';
    classTypesTexts += '  bool Decode(IOBufReader& iobr) override;\n';
    classTypesTexts += '  bool Encode(IOBufWriter& iobw) const override;\n\n';
    classTypesTexts += 'private:\n';

    # if (hasFlags):
    #   classTypesTexts += '  int flags_ {0};\n\n';

    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramName == 'flags'):
        classTypesTexts += '  uint32_t flags_ {0};\n';
      elif (paramType == 'bool'):
        classTypesTexts += '';  #'  bool ' + paramName + '_ {false};\n';
      elif (paramType in ['int32_t', 'int64_t', 'double']):
        classTypesTexts += '  ' +  paramType + ' ' + paramName + '_ {0};\n';
      elif (paramType in TypesList):
        classTypesTexts += '  std::unique_ptr<' + paramType + '> ' + paramName + '_;\n';
      else:
        if (paramType == 'TQueryType'):
          classTypesTexts += '  std::unique_ptr<TLObject> ' + paramName + '_;\n';
        elif (paramType.find('std::vector') >= 0):
          eptype = txt_wrap_by('<', '*', paramType);
          classTypesTexts += '  std::vector<std::unique_ptr<' + eptype + '>> ' + paramName + '_;\n';
        elif (paramType.find('TLObjectVector') >= 0):
          eptype = txt_wrap_by('<', '>', paramType);
          classTypesTexts += '  TLObjectVector<' + eptype + '> ' + paramName + '_;\n';
        else:
          classTypesTexts += '  ' + paramType + ' ' + paramName + '_;\n';

    classTypesTexts += '};\n\n';


    # cc实现
    classFuncsTexts += '//////////////////////////////////////////////////////////////////////////////\n';
    classFuncsTexts += '// ' + name + '\n';
    classFuncsTexts += 'bool TL_' + name + '::Decode(IOBufReader& iobr) {\n';
    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramType in TypesList):
        if (paramName in conditionsList):
          classFuncsTexts += '  if (has_' + paramName + '()) {\n';
          classFuncsTexts += '    auto o = TLObject::CreateObjectByIOBuf(iobr);\n';
          classFuncsTexts += '    if (o == nullptr) return false;\n';
          classFuncsTexts += '    auto o2 = reinterpret_cast<' + paramType + '*>(o);\n';
          classFuncsTexts += '    if (o2 == nullptr) {\n';
          classFuncsTexts += '      delete o;\n';
          classFuncsTexts += '      return false;\n';
          classFuncsTexts += '    }\n';
          classFuncsTexts += '    ' + paramName + '_ = std::unique_ptr<' + paramType + '>(o2);\n';
          classFuncsTexts += '  }\n';
        else:
          classFuncsTexts += '  if (true) {\n';
          classFuncsTexts += '    auto o = TLObject::CreateObjectByIOBuf(iobr);\n';
          classFuncsTexts += '    if (o == nullptr) return false;\n';
          classFuncsTexts += '    auto o2 = reinterpret_cast<' + paramType + '*>(o);\n';
          classFuncsTexts += '    if (o2 == nullptr) {\n';
          classFuncsTexts += '      delete o;\n';
          classFuncsTexts += '      return false;\n';
          classFuncsTexts += '    }\n';
          classFuncsTexts += '    ' + paramName + '_ = std::unique_ptr<' + paramType + '>(o2);\n';
          classFuncsTexts += '  }\n';
      else:
        if (paramType in ['int32_t', 'int64_t', 'double']):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) {\n';
            classFuncsTexts += '    ' + paramName + '_ = iobr.readLE<' + paramType + '>();\n  }\n';
          else:
            classFuncsTexts += '  ' + paramName + '_ = iobr.readLE<' + paramType + '>();\n';
        elif (paramType == 'std::string'):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) {\n';
            classFuncsTexts += '    ReadString(iobr, &' + paramName + '_);\n  }\n';
          else:
            classFuncsTexts += '  ReadString(iobr, &' + paramName + '_);\n';
        elif (paramType in ['TLInt128', 'TLInt256', 'TLInt512', 'TLInt1024', 'TLInt2048']):
          classFuncsTexts += '  ReadTLIntN(iobr, &' + paramName + '_);\n';
        elif (paramType in ['TLInt32Vector', 'TLInt64Vector', 'TLStringVector'] or paramType.find('TLObjectVector') >= 0):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) {\n';
            classFuncsTexts += '    ' + paramName + '_.ParseFromIOBuf(iobr, true);\n  }\n';
          else:
            classFuncsTexts += '  ' + paramName + '_.ParseFromIOBuf(iobr, true);\n';
        elif (paramType.find('std::vector') >= 0):
          eptype = txt_wrap_by('<', '*', paramType);
          classFuncsTexts += '  auto sz = iobr.readLE<uint32_t>();\n';
          classFuncsTexts += '  for (uint32_t i=0; i<sz; ++i) {\n';
          classFuncsTexts += '    auto o = TLObject::CreateObjectByIOBuf(iobr);\n';
          classFuncsTexts += '    if (o->GetClassID() != ' + eptype + '::CLASS_ID) {\n';
          classFuncsTexts += '      delete o;\n';
          classFuncsTexts += '      return false;\n';
          classFuncsTexts += '    }\n';
          classFuncsTexts += '    ' + paramName + '_.push_back(std::unique_ptr<' + eptype + '>(reinterpret_cast<' + eptype + '*>(o)));\n';
          classFuncsTexts += '  }\n';
        else:
          classFuncsTexts += '';

    classFuncsTexts += '  return true;\n';
    classFuncsTexts += '}\n';

    classFuncsTexts += 'bool TL_' + name + '::Encode(IOBufWriter& iobw) const {\n';
    for paramName in prmsList:
      paramType = prms[paramName];
      if (paramType in TypesList):
        if (paramName in conditionsList):
          classFuncsTexts += '  if (has_' + paramName + '()) ' + paramName + '_->SerializeToIOBuf(iobw);\n';
        else:
          classFuncsTexts += '  if (!' + paramName + '_) return false;\n';
          classFuncsTexts += '  ' + paramName + '_-> SerializeToIOBuf(iobw);\n';
      else:
        if (paramType in ['int32_t', 'int64_t', 'double']):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) iobw.writeLE(' + paramName + '_);\n';
          else:
            classFuncsTexts += '  iobw.writeLE(' + paramName + '_);\n';
        elif (paramType == 'std::string'):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) WriteString(iobw, ' + paramName + '_);\n';
          else:
            classFuncsTexts += '  WriteString(iobw, ' + paramName + '_);\n';
        elif (paramType in ['TLInt128', 'TLInt256', 'TLInt512', 'TLInt1024', 'TLInt2048']):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) WriteTLIntN(iobw, ' + paramName + '_);\n';
          else:
            classFuncsTexts += '  WriteTLIntN(iobw, ' + paramName + '_);\n';
        elif (paramType in ['TLInt32Vector', 'TLInt64Vector', 'TLStringVector'] or paramType.find('TLObjectVector') >= 0):
          if (paramName in conditionsList):
            classFuncsTexts += '  if (has_' + paramName + '()) ' + paramName + '_.SerializeToIOBuf(iobw);\n';
          else:
            classFuncsTexts += '  ' + paramName + '_.SerializeToIOBuf(iobw);\n';
        elif (paramType.find('std::vector') >= 0):
          classFuncsTexts += '  iobw.writeLE(' + paramName + '_.size());\n'
          classFuncsTexts += '  for (size_t i=0; i<' + paramName + '_.size(); ++i) {\n';
          classFuncsTexts += '    ' + paramName + '_[i]->SerializeToIOBuf(iobw);\n;'
          classFuncsTexts += '  }\n';
        else:
          classFuncsTexts += '';
    classFuncsTexts += '  return true;\n';
    classFuncsTexts += '}\n\n';

header = '\
/*\n\
 * WARNING! All changes made in this file will be lost!\n\
 * Created from \'scheme.tl\' by \'codegen\'\n\
 *\n\
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula\n\
 *  All rights reserved.\n\
 *\n\
 * Licensed under the Apache License, Version 2.0 (the "License");\n\
 * you may not use this file except in compliance with the License.\n\
 * You may obtain a copy of the License at\n\
 *\n\
 *   http://www.apache.org/licenses/LICENSE-2.0\n\
 *\n\
 * Unless required by applicable law or agreed to in writing, software\n\
 * distributed under the License is distributed on an "AS IS" BASIS,\n\
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n\
 * See the License for the specific language governing permissions and\n\
 * limitations under the License.\n\
 */\n\n\
#ifndef PROTO_MTPROTO_SCHME_TL_H_\n\
#define PROTO_MTPROTO_SCHME_TL_H_\n\n\
#include "nebula/base/crypto_util/crypto_util.h"\n\
#include "proto/mtproto/core/tl_object.h"\n\
#include "proto/mtproto/core/tl_vector.h"\n\n\
namespace mtproto {\n\n\
// Type forward declarations\n\
' + forwards + '\n\n\
' + resClassTypesTexts + '\n\n\
' + classTypesTexts + '\n\n\
}\n\n\
#endif\n';

source = '\
/*\n\
 * WARNING! All changes made in this file will be lost!\n\
 * Created from \'scheme.tl\' by \'codegen\'\n\
 *\n\
 *  Copyright (c) 2016, https://github.com/nebula-im/nebula\n\
 *  All rights reserved.\n\
 *\n\
 * Licensed under the Apache License, Version 2.0 (the "License");\n\
 * you may not use this file except in compliance with the License.\n\
 * You may obtain a copy of the License at\n\
 *\n\
 *   http://www.apache.org/licenses/LICENSE-2.0\n\
 *\n\
 * Unless required by applicable law or agreed to in writing, software\n\
 * distributed under the License is distributed on an "AS IS" BASIS,\n\
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n\
 * See the License for the specific language governing permissions and\n\
 * limitations under the License.\n\
 */\n\n\
#include "proto/mtproto/schema.tl.h"\n\n\
#include "proto/mtproto/core/tl_codec_util.h"\n\n\
using namespace mtproto;\n\n\
' + ''.join(registers) + '\n\n\
' + classFuncsTexts + '\n\n';

already_header = ''
if os.path.isfile(output_header):
  with open(output_header, 'r') as already:
    already_header = already.read()
if already_header != header:
  with open(output_header, 'w') as out:
    out.write(header)

already_source = ''
if os.path.isfile(output_source):
  with open(output_source, 'r') as already:
    already_source = already.read()
if already_source != source:
  with open(output_source, 'w') as out:
    out.write(source)

