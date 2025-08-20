
#include <stdio.h> /* printf */
#include <int.h>
/* 
struct int_CmdOperation,
int_GetOperation,
int_PrintOperation,
_atoi,
_itoa
*/
#include <str.h>
/*
int str_Len(const char * _val);
void str_Cpy( const char * _val, char * _targ);

int str_GetBuffSize(void);
void str_ResetBuf(void);
const char * str_GetInputBuf(void);
void str_PushBuf(char _val);

void cl_Print(const char * _val);
const char * cl_Input(void);

*/

int main(void){
	struct int_CmdOperation cmd;
	
	char strx[11] = {0};
	char stry[11] = {0};
	
	cl_Print("Entre the x integer\n");
	str_Cpy(cl_Input(), strx);
	cl_Print("Entre the y integer\n");
	str_Cpy(cl_Input(), stry);
	
	cmd.x = _atoi(strx);
	cmd.y = _atoi(stry);
	
	cmd.mode = '+';
	int_PrintOperation(cmd);
	
	cmd.mode = '-';
	int_PrintOperation(cmd);
	
	cmd.mode = '*';
	int_PrintOperation(cmd);
	
	return 0;
}
