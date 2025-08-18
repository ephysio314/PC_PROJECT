
#include <stdio.h> /* printf, getchar */
#include <string.h> /* strlen */
#include <stdbool.h>

static char buff[BUFSIZ]=(char[BUFSIZ]){0};

char * cl_Buff(void){
	return buff;
}

bool cl_BuffIsEmpty(void){
	bool b=0;
	b+=(bool)('\0' == buff[0]);
	return b;
}

void cl_Input(void){
	int i=0;
	int imax=BUFSIZ;
	while(1){
		char c = getchar();
		if('\n' == c || EOF == c){ break; }
		else{ buff[i]=c; i++; }
	}
}

int main(void){
	char valide=0;
	while(!valide){
		printf("Enter a sentence\n");
		cl_Input();
		if(!cl_BuffIsEmpty()){ valide=1; }
	}
	
	printf("Input: '%s'; len: '%d'\n", cl_Buff(), (int)strlen(cl_Buff()));
	
	return 0;
}
