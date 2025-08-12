
#include "macro.h" /* struct int_CmdOperation */

/*
~CONVERSION
*/

#include <stdlib.h> /* atoi, itoa */

#define _atoi atoi

void _itoa(int _val, char _targ[]);

/*
~OPERATION
*/

int int_GetOperation(struct int_CmdOperation _cmd);

void int_PrintOperation(struct int_CmdOperation _cmd);

