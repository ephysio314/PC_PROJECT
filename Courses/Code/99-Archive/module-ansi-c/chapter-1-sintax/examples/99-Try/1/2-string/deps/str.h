
/*
~STR
*/

int str_Len(const char * _val);
void str_Cpy( const char * _val, char * _targ);

/*
~BUFF
*/

int str_GetBuffSize(void);
void str_ResetBuf(void);
const char * str_GetInputBuf(void);
void str_PushBuf(char _val);

/*
~CLI
*/

void cl_Print(const char * _val);
const char * cl_Input(void);

