
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
str_Len,
str_Cpy,

str_GetBuffSize,
str_SetBuffStream,
str_ResetBuf,
*/

#include <cl.h>
/*
void cl_Print(const char * _val);
const char * cl_Input(void);
*/

int main(void){
	struct int_CmdOperation cmd;
	
	cl_PrintStr("Entre the x integer\n");
	cmd.x = _atoi(cl_Input());
	
	cl_PrintStr("Entre the y integer\n");
	cmd.y = cl_IntInput();
	
	cl_PrintStr("We enter the number '");
	cl_PrintInt(cmd.x);
	cl_PrintStr("' and '");
	cl_PrintInt(cmd.y);
	cl_PrintStr("'\n");
	
	cmd.mode = '+';
	int_PrintOperation(cmd);
	
	cmd.mode = '-';
	int_PrintOperation(cmd);
	
	cmd.mode = '*';
	int_PrintOperation(cmd);
	
	return 0;
}
