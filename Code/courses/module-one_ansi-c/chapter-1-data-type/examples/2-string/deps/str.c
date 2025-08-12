
#include "str.h" /* str_buff.c */

#include <stdio.h> /* stdout, fputc */
#include <limits.h> /* INT_MAX */

#include <string.h> /* memset */

int str_Len(const char * _val){
	if(NULL != _val){ 
		int i=0;
		int imax=INT_MAX;
		while(i < imax){
			if('\0' == _val[i]){ return i; }
			i++;
		} /* i < imax */
	} /* NULL != _val */
	return 0;
}

void str_Cpy( const char * _val, char * _targ){
	int val_len = str_Len(_val);
	if(0 != val_len){
		int i=0;
		int imax=val_len;
		while(i < imax && '\0' != _val[i]){
			_targ[i]=_val[i];
			i++;
		}
	}
}

/*
~VIEW
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
	return str_GetBuf();
}

