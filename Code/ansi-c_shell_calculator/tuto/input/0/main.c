
#include <stdio.h> /* printf stdin fgetc */
#include <string.h> /* strlen */

static char buf[BUFSIZ] = (char[BUFSIZ]){0};

void ResetBuf(void){
	memset(buf, '\0', sizeof(char) * BUFSIZ);
}

const char * Input(void){
	ResetBuf();
	int i=0;
	int imax=BUFSIZ;
	while(1){
		char c = fgetc(stdin);
		if(EOF == c || '\n' == c){ break; }
		else if(i < imax){ buf[i] = c; i++; }
	}
	return buf;
}

int main(void){

	printf("Input a string\n");
	const char * val = Input();
	printf("Output: '%s'\n", val);

	return 0;
}
