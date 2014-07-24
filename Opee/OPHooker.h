//
//  OPHooker.h
//  Opee
//
//  Created by Alexander S Zielenski on 7/23/14.
//  Copyright (c) 2014 Alex Zielenski. All rights reserved.
//

#ifndef __Opee__OPHooker__
#define __Opee__OPHooker__

// OPHook doesn't support functions with variadic arguments
// if you need to support that, you must define your functions without macros
// and use OPHookFunctionPtr
#define OPHook(TYPE, NAME, CALL, ARGS...) \
__unused static TYPE (*$O_ ##NAME)(ARGS); \
static TYPE $_##NAME(TYPE (*_old)(ARGS), ##ARGS); \
static TYPE O_##NAME(ARGS) {\
return $_##NAME CALL;\
}\
static TYPE $_##NAME(TYPE (*_old)(ARGS), ##ARGS)

#define OPHook0(TYPE, NAME) OPHook(TYPE, NAME, ($O_##NAME))
#define OPHook1(TYPE, NAME, TYPE1, ARG1) OPHook(TYPE, NAME, ($O_##NAME, ARG1), TYPE1 ARG1)
#define OPHook2(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2), TYPE1 ARG1, TYPE2 ARG2)
#define OPHook3(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3)
#define OPHook4(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3, ARG4), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4)
#define OPHook5(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4, TYPE5, ARG5) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3, ARG4, ARG5), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4, TYPE5 ARG5)
#define OPHook6(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4, TYPE5, ARG5, TYPE6, ARG6) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4, TYPE5 ARG5, TYPE6 ARG6)
#define OPHook7(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4, TYPE5, ARG5, TYPE6, ARG6, TYPE7, ARG7) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4, TYPE5 ARG5, TYPE6 ARG6, TYPE7 ARG7)
#define OPHook8(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4, TYPE5, ARG5, TYPE6, ARG6, TYPE7, ARG7, TYPE8, ARG8) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4, TYPE5 ARG5, TYPE6 ARG6, TYPE7 ARG7, TYPE8 ARG8)
#define OPHook9(TYPE, NAME, TYPE1, ARG1, TYPE2, ARG2, TYPE3, ARG3, TYPE4, ARG4, TYPE5, ARG5, TYPE6, ARG6, TYPE7, ARG7, TYPE8, ARG8, TYPE9, ARG9) OPHook(TYPE, NAME, ($O_##NAME, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9), TYPE1 ARG1, TYPE2 ARG2, TYPE3 ARG3, TYPE4 ARG4, TYPE5 ARG5, TYPE6 ARG6, TYPE7 ARG7, TYPE8 ARG8, TYPE9 ARG9)

#define OPHookFunction(NAME) \
OPHookFunctionPtr(NAME, O_##NAME, (void **)&$O_##NAME)

// Only works in function hooks defined by OPHook
#define OPOldCall(ARGS...) _old(ARGS)

#include <stdio.h>

// this is a wrapper around mach_override incase we ever stop using it so API remains constant
int OPHookFunctionPtr(void *symbol, void *replace, void **result);
void *OPFindSymbol(const char *name);

#endif /* defined(__Opee__OPHooker__) */
