
int str_Len(const char * _val);
void str_Cpy( const char * _val, char * _targ);

void str_Print(const char * _val);

void str_CreatBuff(int _len);
void str_FreeBuff(void);
void str_ResetBuff(void);
const char * str_GetBuff(void);
int str_BuffLen(void);

const char * str_Input(void);

void file_Write(const char * _val);
int file_Len(void);
void file_LoadBuff(void);

