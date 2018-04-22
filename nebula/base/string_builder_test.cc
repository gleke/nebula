//============================================================================
// Name        : StringBuilderDemo.cpp
// Author      : Pablo Aliskevicius
// Copyright   : Licensed under the Code Project Open License
// Description : std::basic_string<>::reserve can save _lots_ of time in reallocations.
//               Using std::accumulate on strings can have a _big_ performance cost.
// Version II modifications:
//      1.  Added std::basic_stringstream to the tests.
//          Thanks to http://www.codeproject.com/script/Membership/View.aspx?mid=797594
//      2.  Removed a function that is no longer relevant.
// 		3.	Performance test with side effects, so the compiler doesn't optimize it away.
// 			Inspired on the code at http://code.google.com/p/strtk/source/browse/trunk/strtk_tokenizer_cmp.cpp#699
//          There are two modifications:
//          a. Less tests (4001 instead of 40000 * number of items in vector)
//          b. Using ^= instead of if ... += else ... -=.
// 			Thanks to: http://www.codeproject.com/script/Membership/View.aspx?mid=1256594
//      4.  Added this lambda:
//          for_each(test.begin(), test.end(), [&](const std::wstring &s){ accumulator += s; });
//          Thanks to http://www.codeproject.com/script/Membership/View.aspx?mid=10171025
//
// C++ 11 Support in Eclipse:
//  		See http://stackoverflow.com/questions/9131763/eclipse-cdt-c11-c0x-support
//============================================================================

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

#include "nebula/base/string_builder.h"

#include <iostream> // for std::cout
#include <fstream>
#include <sstream>
#include <algorithm> // for for_each
#include <ctime>    // clock_t, clock, CLOCKS_PER_SEC

#ifdef __USE_POSIX199309

class StopWatch {
  enum { clockId = CLOCK_THREAD_CPUTIME_ID };
  timespec m_startTime;
  timespec m_endTime;
  double m_seconds;
public:
  static timespec diff(timespec start, timespec end)
  {
		// Thanks to Guy Rutenberg: http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/
		// Don't forget to add -lrt to the g++ linker command line.
		timespec temp;
		if ((end.tv_nsec-start.tv_nsec)<0) {
      temp.tv_sec = end.tv_sec-start.tv_sec-1;
      temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
      temp.tv_sec = end.tv_sec-start.tv_sec;
      temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
		return temp;
  }
  
  static double ToSeconds(const timespec &diff) {
    return diff.tv_sec + diff.tv_nsec / 1e9;
  }
  
  void Start() {
    clock_gettime(clockId, &m_startTime);
  }
  void Stop() {
    clock_gettime(clockId, &m_endTime);
    m_seconds = ToSeconds(diff(m_startTime, m_endTime));
  }
  double GetSeconds() const {
    return m_seconds;
  }
  StopWatch() {
    Start();
  }
}; // struct StopWatch

void TestPerformance(const StringBuilder<wchar_t> &tested, const std::vector<std::wstring> &tested2) {
  const int loops = 4001; // Odd number to keep 1 result at the end.
  ////////////////
  // Test std::accumulate()
  ////////////////
  std::wstring accumulate_result;
  size_t accumulate_len = 0;
  StopWatch swAccumulate;
  for (int i = 0; i < loops; ++i) {
    std::wstring accumulator;
    accumulate_result = std::accumulate(tested2.begin(), tested2.end(), accumulator);
    accumulate_len ^= accumulate_result.size();
  }
  swAccumulate.Stop();
  using std::cout;
  using std::endl;
  cout << "\tstd::accumulate: " << swAccumulate.GetSeconds() << ": size " << accumulate_len << endl;
  ////////////////
  // Test ToString()
  ////////////////
  std::wstring toString_result;
  size_t toString_len = 0;
  StopWatch swToString;
  for (int i = 0; i < loops; ++i) {
    toString_result = tested.ToString();
    toString_len ^= toString_result.size();
  }
  swToString.Stop();
  cout << "\tToString: " << swToString.GetSeconds() << ": size " << toString_len << endl;
  ////////////////
  // Test join()
  ////////////////
  std::wstring join_result;
  size_t join_len = 0;
  StopWatch swJoin;
  for (int i = 0; i < loops; ++i) {
    join_result = tested.Join(L",");
    join_len ^= join_result.size();
  }
  swJoin.Stop();
  cout << "\tJoin: " << swJoin.GetSeconds() << ": size " << join_len << endl;
  
  ////////////////
  // basic_ostringstream<wchar_t>
  // First test: only getting the string, not filling the stream.
  ////////////////
  typedef std::basic_ostringstream<wchar_t> wostringstream;
  wostringstream woss;
  for(size_t j = 0; j < tested2.size(); ++j)
    woss << tested2[j];
  std::wstring stringStream_result;
  size_t stringStream_len = 0;
  StopWatch swStringStream;
  for (int i = 0; i < loops; ++i) {
    stringStream_result = woss.str();
    stringStream_len ^= stringStream_result.size();
  }
  swStringStream.Stop();
  cout << "\tostringstream: " << swStringStream.GetSeconds() << ": size " << stringStream_len << endl;
  
  ////////////////
  // Test lambda
  ////////////////
  
  std::wstring strAccumulator;
  size_t lambdaResult_len = 0;
  StopWatch swLambda;
  for (int i = 0; i < loops; ++i) {
    std::wstring strtmp;
    std::for_each(tested2.begin(), tested2.end(), [&](const std::wstring &s){ strtmp += s; });
    if (0 == i) {
      strAccumulator = strtmp;
    }
    lambdaResult_len ^= strtmp.size();
  }
  swLambda.Stop();
  cout << "\tLambda: " << swLambda.GetSeconds() << ": size " << lambdaResult_len << endl;
  
  ////////////////
  // Show results so far.
  ////////////////
  cout << "* Performance test:" << endl
  << "    Accumulate took " << swAccumulate.GetSeconds() << " seconds, and ToString() took " << swToString.GetSeconds() << " seconds." << endl
  << "    The relative speed improvement was " << ((swAccumulate.GetSeconds() / swToString.GetSeconds()) - 1) * 100 << "%" << endl
  << "    std::ostringstream took " << swStringStream.GetSeconds() << " with a relative speed improvement of "  << ((swAccumulate.GetSeconds() / swStringStream.GetSeconds()) - 1) * 100 << "% (winning, you say?)" << endl
  << "    lambda took " << swLambda.GetSeconds() << " with a relative speed improvement of "  << ((swAccumulate.GetSeconds() / swLambda.GetSeconds()) - 1) * 100 << "% (winning, you say?)" << endl
  << "    Join took " << swJoin.GetSeconds() << " seconds."
  << endl;
  
  ////////////////
  // basic_ostringstream<wchar_t> and tostring: fill and execute.
  ////////////////
  
  if (true) {
    size_t tmp = 0;
    typedef std::basic_ostringstream<wchar_t> wostringstream;
    StopWatch swStringStream2;
    for (int i = 0; i < loops; ++i) {
      wostringstream woss;
      for(size_t j = 0; j < tested2.size(); ++j)
			     woss << tested2[j];
      /*
       for (auto iter = tested2.begin(); iter != tested2.end(); ++iter) {
       woss << *iter;
       }
       */
      tmp ^= woss.str().size();
    }
    swStringStream2.Stop();
    cout << "\tostringstream (fill and convert to string): " << swStringStream2.GetSeconds() << ", length " << tmp << endl;
  }
  if (true) {
    size_t tmp = 0;
    StopWatch swToString2;
    for (int i = 0; i < loops; ++i) {
      StringBuilder<wchar_t> test;
      test.Add(tested2.begin(), tested2.end());
      tmp ^= test.ToString().size();
    }
    swToString2.Stop();
    cout << "\tToString (fill and convert to string): " << swToString2.GetSeconds() << ", length " << tmp << endl;
  }
}
#endif // def __USE_POSIX199309

std::vector<std::wstring> GetVector (const char * fileName) {
  // http://www.cplusplus.com/doc/tutorial/files/
  // reading a text file
  using namespace std;
  wstring line;
  vector<wstring> results;
  wifstream inputFile (fileName);
  if (inputFile.is_open())
    {
    while ( getline (inputFile,line) )
      {
      results.push_back(line);
      }
    inputFile.close();
    }
  return results;
}

std::vector<std::wstring> GetWordByWordVector() {
  // From http://en.wikipedia.org/wiki/Cargo_cult
  static std::vector<std::wstring> cargoCult =
		{
    L"A", L" cargo", L" cult", L" is", L" a", L" kind", L" of", L" Melanesian", L" millenarian", L" movement",
    L" encompassing", L" a", L" diverse", L" range", L" of", L" practices", L" and", L" occurring", L" in",
    L" the", L" wake", L" of", L" contact", L" with", L" the", L" commercial", L" networks", L" of", L" colonizing",
    L" societies.", L" The", L" name", L" derives", L" from", L" the", L" apparent", L" belief", L" that", L" various",
    L" ritualistic", L" acts", L" will", L" lead", L" to", L" a", L" bestowing", L" of", L" material", L" wealth",
    L" (\"cargo\").", L" Cargo", L" cults", L" often", L" develop", L" during", L" a", L" combination", L" of",
    L" crises.", L" Under", L" conditions", L" of", L" social", L" stress,", L" such", L" a", L" movement", L" may",
    L" form", L" under", L" the", L" leadership", L" of", L" a", L" charismatic", L" figure.", L" This", L" leader",
    L" may", L" have", L" a", L" 'vision'", L" (or", L" 'myth-dream')", L" of", L" the", L" future,", L" often", L" linked",
    L" to", L" an", L" ancestral", L" efficacy", L" thought", L" to", L" be", L" recoverable", L" by", L" a", L" return",
    L" to", L" traditional", L" morality.\n", L" This", L" leader", L" may", L" characterize", L" the", L" present",
    L" state", L" (often", L" imposed", L" by", L" colonial", L" capitalist", L" regimes)", L" as", L" a", L" dismantling",
    L" of", L" the", L" old", L" social", L" order,", L" meaning", L" that", L" social", L" hierarchy", L" and", L" ego",
    L" boundaries", L" have", L" been", L" broken", L" down.", L" Contact", L" with", L" colonizing", L" groups", L" brought",
    L" about", L" a", L" considerable", L" transformation", L" in", L" the", L" way", L" indigenous", L" peoples", L" of",
    L" Melanesia", L" have", L" thought", L" about", L" other", L" societies.", L" Early", L" theories", L" of", L" cargo",
    L" cults", L" began", L" from", L" the", L" assumption", L" that", L" practitioners", L" simply", L" failed", L" to",
    L" understand", L" technology,", L" colonization,", L" or", L" capitalist", L" reform;", L" in", L" this", L" model,",
    L" cargo", L" cults", L" are", L" a", L" misunderstanding", L" of", L" the", L" trade", L" networks", L" involved", L" in",
    L" resource", L" distribution", L" and", L" an", L" attempt", L" to", L" acquire", L" such", L" goods", L" in", L" the",
    L" wake", L" of", L" interrupted", L" trade.", L" However,", L" many", L" of", L" these", L" practitioners", L" actually",
    L" focus", L" on", L" the", L" importance", L" of", L" sustaining", L" and", L" creating", L" new", L" social",
    L" relationships,", L" with", L" material", L" relations", L" being", L" secondary.\n",
    L"Since", L" the", L" late", L" twentieth", L" century,", L" alternative", L" theories", L" have", L" arisen.", L" For", L" example,", L" some", L" scholars,", L" such", L" as", L" Kaplan", L" and", L" Lindstrom,", L" focus", L" on", L" Europeans'", L" characterization", L" of", L" these", L" movements", L" as", L" a", L" fascination", L" with", L" manufactured", L" goods", L" and", L" what", L" such", L" a", L" focus", L" says", L" about", L" Western", L" commodity", L" fetishism.\n", L" Others", L" point", L" to", L" the", L" need", L" to", L" see", L" each", L" movement", L" as", L" reflecting", L" a", L" particularized", L" historical", L" context,", L" even", L" eschewing", L" the", L" term", L" \"cargo", L" cult\"", L" for", L" them", L" unless", L" there", L" is", L" an", L" attempt", L" to", L" elicit", L" an", L" exchange", L" relationship", L" from", L" Europeans.\n",
    L"Causes, beliefs, and practices\n",
    L"Cargo", L" cults", L" are", L" marked", L" by", L" a", L" number", L" of", L" common", L" characteristics,", L" including", L" a", L" 'myth-dream'", L" that", L" is", L" a", L" synthesis", L" of", L" indigenous", L" and", L" foreign", L" elements;", L" the", L" expectation", L" of", L" help", L" from", L" the", L" ancestors;", L" charismatic", L" leaders;", L" and", L" lastly,", L" belief", L" in", L" the", L" appearance", L" of", L" an", L" abundance", L" of", L" goods.\n",
    L"The", L" indigenous", L" societies", L" of", L" Melanesia", L" were", L" typically", L" characterized", L" by", L" a", L" 'Big", L" Man'", L" political", L" system", L" in", L" which", L" individuals", L" gained", L" prestige", L" through", L" gift", L" exchanges.", L" The", L" more", L" wealth", L" a", L" man", L" could", L" distribute,", L" the", L" more", L" people", L" in", L" his", L" debt,", L" and", L" the", L" greater", L" his", L" renown.", L" Those", L" who", L" were", L" unable", L" to", L" reciprocate", L" were", L" identified", L" as", L" 'Rubbish", L" men'.", L" Faced,", L" through", L" colonialism,", L" with", L" foreigners", L" with", L" a", L" seemingly", L" unending", L" supply", L" of", L" goods", L" for", L" exchange,", L" indigenous", L" Melanesians", L" experienced", L" 'value", L" dominance.'", L" That", L" is,", L" they", L" were", L" dominated", L" by", L" others", L" in", L" terms", L" of", L" their", L" own", L" (not", L" the", L" foreign)", L" value", L" system;", L" exchange", L" with", L" foreigners", L" left", L" them", L" feeling", L" like", L" Rubbish", L" men.\n",
    L"Since", L" the", L" modern", L" manufacturing", L" process", L" is", L" unknown", L" to", L" them,", L" members,", L" leaders,", L" and", L" prophets", L" of", L" the", L" cults", L" maintain", L" that", L" the", L" manufactured", L" goods", L" of", L" the", L" non-native", L" culture", L" have", L" been", L" created", L" by", L" spiritual", L" means,", L" such", L" as", L" through", L" their", L" deities", L" and", L" ancestors.", L" These", L" goods", L" are", L" intended", L" for", L" the", L" local", L" indigenous", L" people,", L" but", L" the", L" foreigners", L" have", L" unfairly", L" gained", L" control", L" of", L" these", L" objects", L" through", L" malice", L" or", L" mistake.\n", L" Thus,", L" a", L" characteristic", L" feature", L" of", L" cargo", L" cults", L" is", L" the", L" belief", L" that", L" spiritual", L" agents", L" will,", L" at", L" some", L" future", L" time,", L" give", L" much", L" valuable", L" cargo", L" and", L" desirable", L" manufactured", L" products", L" to", L" the", L" cult", L" members.\n",
    L"Symbols", L" associated", L" with", L" Christianity", L" and", L" modern", L" Western", L" society", L" tend", L" to", L" be", L" incorporated", L" into", L" their", L" rituals", L" as", L" magical", L" artifacts,", L" for", L" example", L" the", L" use", L" of", L" cross-shaped", L" grave", L" markers.", L" Notable", L" examples", L" of", L" cargo", L" cult", L" activity", L" include", L" the", L" setting", L" up", L" of", L" mock", L" airstrips,", L" airports,", L" offices,", L" and", L" dining", L" rooms,", L" as", L" well", L" as", L" the", L" fetishization", L" and", L" attempted", L" construction", L" of", L" Western", L" goods,", L" such", L" as", L" radios", L" made", L" of", L" coconuts", L" and", L" straw.", L" Believers", L" may", L" stage", L" \"drills\"", L" and", L" \"marches\"", L" with", L" sticks", L" for", L" rifles", L" and", L" use", L" military-style", L" insignia", L" and", L" national", L" insignia", L" painted", L" on", L" their", L" bodies", L" to", L" make", L" them", L" look", L" like", L" soldiers,", L" thereby", L" treating", L" the", L" activities", L" of", L" Western", L" military", L" personnel", L" as", L" rituals", L" to", L" be", L" performed", L" for", L" the", L" purpose", L" of", L" attracting", L" the", L" cargo.\n",
    L"Examples:\n",
    L"The", L" term", L" 'Cargo", L" cult'", L" was", L" first", L" used", L" in", L" print", L" in", L" 1945", L" by", L" Norris", L" Mervyn", L" Bird,", L" repeating", L" a", L" derogatory", L" description", L" used", L" by", L" planters", L" and", L" businessmen", L" in", L" the", L" Australian", L" protectorate", L" of", L" Papua.", L" The", L" term", L" was", L" later", L" adopted", L" by", L" anthropologists,", L" and", L" applied", L" retroactively", L" to", L" movements", L" in", L" a", L" much", L" earlier", L" era.\n"
    };
  
  return cargoCult;
}
int main(int argc, char **argv) {
  ////////////////////////////////////
  // ANSI, chaining.
  ////////////////////////////////////
  std::cout << argv[0] << std::endl;
  StringBuilder<char> ansi;
  ansi.Append("Hello").Append(" ").AppendLine("World!");
  std::cout << ansi.ToString();
  
  ////////////////////////////////////
  // Unicode
  ////////////////////////////////////
  StringBuilder<wchar_t> wide;
  
  // Load from text file, to make it 'not deterministic'.
  std::vector<std::wstring> cargoCult = GetVector("./cargoCult.txt");
  // Files are not always there.
  if (!cargoCult.empty())
    {
    // The .AppendLine() call at the end of the chain explains the extra character in the length.
    wide.Add(cargoCult.begin(), cargoCult.end()).AppendLine();
    std::wstring cargoCultString = wide.ToString();
    std::wcout << cargoCultString << std::endl << "Length " << cargoCultString.size() <<  std::endl;
    // javascript-like join.
    std::wcout << wide.Join(L" _\n") << std::endl;
    
#ifdef __USE_POSIX199309
    std::wcout << std::endl << L"Testing long lines" << std::endl;
    TestPerformance(wide, cargoCult);
#endif // def __USE_POSIX199309
    }
  // The text file has a few long strings.
  // This version, many short strings
  cargoCult = GetWordByWordVector();
  // The .AppendLine() call at the end of the chain explains the extra character in the length.
  wide.Clear().Add(cargoCult.begin(), cargoCult.end()).AppendLine();
#ifdef __USE_POSIX199309
  std::wcout << std::endl << L"Testing word by word" << std::endl;
  TestPerformance(wide, cargoCult);
#endif // def __USE_POSIX199309
  
  return 0;
}
