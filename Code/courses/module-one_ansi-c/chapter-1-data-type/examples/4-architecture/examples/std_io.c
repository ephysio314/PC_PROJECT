
#include <stdio.h>
/*
stdout
stdin
fgetc
fputc
*/

#include <string.h>
/*
strlen
*/

#include <stdlib.h>
/*
calloc
free
*/

void str_Print(const char * _val){
	if(NULL != _val){
		int i=0;
		int imax=(int)strlen(_val);
		while(i < imax){
			fputc(_val[i], stdout);
			i++;
		} /* i < imax */
	} /* NULL != _val */
}

static char buf[BUFSIZ] = (char[BUFSIZ]){0};

void str_ResetBuf(void){
	memset(buf, '\0', sizeof(char) * BUFSIZ);
}

const char * str_Input(void){
	str_ResetBuf();
	int i=0;
	int imax=BUFSIZ;
	while(1){
		char c = fgetc(stdin);
		if(EOF == c || '\n' == c){ break; }
		else if(i < imax){ buf[i] = c; i++; }
	}
	return buf;
}

const char * str_GetBuf(void){
	return buf;
}

int main(void){
	str_Print("Enter your name\n");
	str_Input();
	int len=(int)strlen(str_GetBuf())+1;
	char * str=(char*)calloc(sizeof(char), len);
	strcpy(str, str_GetBuf());
	
	str_Print("Your name was ");
	str_Print(str);
	str_Print("\n");
	
	free(str);
	
	return 0;
}
