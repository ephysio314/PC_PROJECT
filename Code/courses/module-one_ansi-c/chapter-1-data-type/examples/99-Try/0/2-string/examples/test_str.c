
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
str_Len
str_Cpy

str_Print

str_CreatBuff
str_FreeBuff
str_ResetBuff
str_GetBuff
str_BuffLen

str_Input

file_Write
file_Len
file_LoadBuff
*/

int main(void){
	struct int_CmdOperation cmd;
	
	char strx[11] = {0};
	char stry[11] = {0};
	
	str_Print("Entre the x integer\n");
	str_Cpy(str_Input(), strx);
	str_Print("Entre the y integer\n");
	str_Cpy(str_Input(), stry);
	
	cmd.x = _atoi(strx);
	cmd.y = _atoi(stry);
	
	cmd.mode = '+';
	int_PrintOperation(cmd);
	
	cmd.mode = '-';
	int_PrintOperation(cmd);
	
	cmd.mode = '*';
	int_PrintOperation(cmd);
	
	/*
	~FILE
	*/
	
	file_Write("Hello, World!");
	file_LoadBuff();
	printf("Stream: '%s'\n", str_GetBuff());
	
	str_FreeBuff();
	
	return 0;
}
