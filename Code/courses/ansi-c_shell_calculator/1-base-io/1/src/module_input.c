
#include <stdio.h> /* stdin, fgetc, BUFSIZ */

void _print(const char * _val);

static char buf[BUFSIZ] = {0};

char * _input(const char * _msg){
	_print(_msg);
	
	int i=0;
	int imax=BUFSIZ;
	while(1){
		char c=fgetc(stdin);
		if(EOF == c || '\n' == c || '\0' == c){ break; }
		else if(i < imax){ buf[i]; i++; }
	}
	return buf;
}

