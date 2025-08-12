
#include <stdio.h> /* FILE* */

int str_Len(const char * _val);
void str_Cpy( const char * _val, char * _targ);

/*
~VIEW
*/

void str_Print(const char * _val);

/*
~CONTROL
*/

int str_GetBuffSize(void);
void str_SetBuffStream(FILE*_stream);
void str_ResetBuf(void);
const char * str_Input(void);
const char * str_GetInputBuf(void);

