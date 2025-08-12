
#include "int.h" /* int_conversion.c, int_operation */
#include "str.h" /* str.c str_buff.c */

#include <stdio.h> /* stdout, fputc */
#include <limits.h> /* INT_MAX */

#include <string.h> /* memset */

void cl_PrintStr(const char * _val){
	int i=0;
	int imax=str_Len(_val);
	while(i < imax){
		fputc(_val[i], stdout);
		i++;
	}
}
void cl_PrintInt(const int _val){
	char buff[11]={0};
	_itoa(_val, buff);
	cl_PrintStr(buff);
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
	return str_GetBuf();
}

