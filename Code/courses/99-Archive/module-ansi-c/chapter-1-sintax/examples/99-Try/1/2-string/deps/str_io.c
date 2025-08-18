
#include "str.h" /* str.c, str_buff.c */

#include <stdio.h> /* stdout, stdin, fputc */

#include <string.h> /* memset */

/*
~CLI
*/

void cl_Print(const char * _val){
	int i=0;
	int imax=str_Len(_val);
	while(i < imax){
		fputc(_val[i], stdout);
		i++;
	}
}

const char * cl_Input(void){
	str_ResetBuf();
	int i=0;
	int imax=str_GetBuffSize();
	while(1){
		char c = fgetc(stdin);
		if(EOF == c || '\n' == c){ break; }
		else if(i < imax){ str_PushBuf(c); i++; }
	}
	return str_GetInputBuf();
}

