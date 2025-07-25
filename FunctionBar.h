#ifndef HEADER_FunctionBar
#define HEADER_FunctionBar
/*
htop - FunctionBar.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include <stdbool.h>
#include <stdint.h>


typedef struct FunctionBar_ {
   char** functions;
   union {
      char** keys;
      const char* const* constKeys;
   } keys;
   int* events;
   uint32_t size;
   bool staticData;
} FunctionBar;

#define FUNCTIONBAR_MAXEVENTS 15

FunctionBar* FunctionBar_newEnterEsc(const char* enter, const char* esc);

FunctionBar* FunctionBar_new(const char* const* functions, const char* const* keys, const int* events);

void FunctionBar_delete(FunctionBar* this);

void FunctionBar_setLabel(FunctionBar* this, int event, const char* text);

int FunctionBar_draw(const FunctionBar* this);

int FunctionBar_drawExtra(const FunctionBar* this, const char* buffer, int attr, bool setCursor);

void FunctionBar_append(const char* buffer, int attr);

int FunctionBar_synthesizeEvent(const FunctionBar* this, int pos);

#endif
