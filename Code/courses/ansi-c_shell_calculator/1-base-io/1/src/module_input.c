
#include <stdio.h> /* stdin, fgetc, BUFSIZ */
#include <string.h> /* strlen */

void _print(const char * _val);

static char buf[BUFSIZ] = {0};

char * _input(const char * _msg){
	int i;
	int imax;
	
	i=0;
	imax=(int)strlen(buf);
	while(i < imax){
		buf[i]='\0';
		i++;
	}	
	
	_print(_msg);
	
	i=0;
	imax=BUFSIZ;
	while(1){
		char c=fgetc(stdin);
		if(EOF == c || '\n' == c || '\0' == c){ break; }
		else if(i < imax){ buf[i]=c; i++; }
	}
	return buf;
}

