
#include <stdio.h> /* stdout, fputc */
#include <string.h> /* strlen */

void _print(const char * _val){
	if(NULL != _val && '\0' != _val[0]){
		int i=0;
		int imax=(int)strlen(_val);
		while(i < imax){
			char c=_val[i];
			fputc(c, stdout);
			i++;
		} /* i < imax */
	} /* NULL != _val && '\0' != _val[0] */
}

