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

output_header = output_path + '/zrpc_messenger_dispatcher.h'
output_source = output_path + '/zrpc_messenger_dispatcher.cc'

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
    # registers.append('REGISTER_TLOBJECT(TL_' + name + ');\n');

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

#funcsList.sort();
#print(funcsList);
funcs = [];

for restype in funcsList:
  v = funcsDict[restype];
  resType = FuncsDict[restype];

  for data in v:
    funcs.append([data[0], resType]);

funcs.sort();
print(funcs);

for v in funcs:
    name = v[0];
    resType = v[1];

    # classTypesTexts += '// ' + line + '\n'; # type class declaration

    registers.append('  ZRpcUtil::Register(mtproto::TL_' + name + '::CLASS_ID, ' + name + ');\n');

    # // help.getConfig#c4f9186b = Config;
    # virtual int help_getConfig(const mtproto::TL_help_getConfig& request, std::shared_ptr<mtproto::Config>& response);
    # static zproto::ProtoRpcResponsePtr help_getConfig(zproto::RpcRequestPtr request);
    classTypesTexts += 'static zproto::ProtoRpcResponsePtr ' + name + '(zproto::RpcRequestPtr request);\n';

    classFuncsTexts += 'zproto::ProtoRpcResponsePtr ZRpcMessengerDispatcher::' + name + '(zproto::RpcRequestPtr request) {\n';
    classFuncsTexts += '  CAST_RPC_REQUEST(mtproto::TL_' + name + ', req);\n';
    classFuncsTexts += '  LOG(INFO) << "' + name + ' - req: " << req.ToString();\n\n';
    classFuncsTexts += '  std::shared_ptr<mtproto::' + resType + '> rsp;\n';
    classFuncsTexts += '  AuthServiceImpl impl;\n';
    classFuncsTexts += '  impl.Initialize(request);\n';
    classFuncsTexts += '  impl.' + name + '(req, rsp);\n';
    classFuncsTexts += '  return mtproto::MakeRpcOK(rsp.get());\n}\n\n';

    # classTypesTexts += 'virtual int ' + name + '(const mtproto::TL_' + name + '& request, std::shared_ptr<mtproto::' + resType + '>& response);\n\n';

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
#ifndef TELEGRAM_CORE_SCHME_TL_H_\n\
#define TELEGRAM_CORE_SCHME_TL_H_\n\n\
#include "nebula/base/crypto_util/crypto_util.h"\n\
#include "nebula/net/telegram/core/tl_object.h"\n\
#include "nebula/net/telegram/core/tl_vector.h"\n\
// Type forward declarations\n\
' + forwards + '\n\n\
' + resClassTypesTexts + '\n\n\
' + classTypesTexts + '\n\n\
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
#include "nebula/net/telegram/schema.tl.h"\n\n\
#include "nebula/net/telegram/core/tl_codec_util.h"\n\n\
ZRpcMessengerDispatcher::ZRpcMessengerDispatcher() { \n\
' + ''.join(registers) + '}\n\n\
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

