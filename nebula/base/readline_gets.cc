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

#include "nebula/base/readline_gets.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
// #include <string>

#include <readline/readline.h>
#include <readline/history.h>

// http://web.mit.edu/gnu/doc/html/rlman_2.html
/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
std::string ReadlineGets (const char* prompt) {
  std::string line;

  /* Get a line from the user. */
  char* g_line_read = readline(prompt);
  
  /* If the line has any text in it, save it on the history. */
  if (g_line_read) {
    if (*g_line_read) {
      add_history (g_line_read);
      line = g_line_read;
    }
    
    free(g_line_read);
  }
  
  return line;
}
