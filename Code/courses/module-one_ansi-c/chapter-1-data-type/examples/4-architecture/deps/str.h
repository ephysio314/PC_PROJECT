
int str_Len(const char * _val);
void str_Cpy( const char * _val, char * _targ);

/*
~BUFF
*/

int str_GetBuffSize(void);
void str_ResetBuf(void);
const char * str_GetBuf(void);
void str_PushBuf(const char _val);

/*
~INPUT/OUPUT
*/

void cl_Print(const char * _val);
const char * cl_Input(void);

