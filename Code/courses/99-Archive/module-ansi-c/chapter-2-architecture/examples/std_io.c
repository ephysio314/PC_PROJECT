
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
strcpy
*/

#include <stdlib.h>
/*
calloc
free
*/

void cl_Print(const char * _val){
	if(NULL != _val){
		int i=0;
		int imax=(int)strlen(_val);
		while(i < imax){
			fputc(_val[i], stdout);
			i++;
		} /* i < imax */
	} /* NULL != _val */
}

static char cl_buff[BUFSIZ] = {0};

const char * cl_InputBuff(void){
	return cl_buff;
}

void cl_Input(void){

	memset(cl_buff, '\0', sizeof(char) * BUFSIZ); /* reset */
	
	int i=0;
	int imax=BUFSIZ;
	while(1){
		char c = fgetc(stdin);
		if(EOF == c || '\n' == c){ break; }
		else if(i < imax){ cl_buff[i] = c; i++; }
	}
}

char test_input_output_string(void){

	/* DESCR */

	printf("Call: '%s'\n", __FUNCTION__);

	const char descr[]=""
		"descr:\n"
		"Input a string and output in the shell\n"
		"using standard io.\n";

	cl_Print(descr);
	
	/* TEST */
	
	char * out=NULL;
	char valide=0;
	while(valide){
		cl_Print("Enter a sentence\n");
		cl_Input();
		
		out=(char*)calloc(sizeof(char), (int)strlen(cl_InputBuff())+1);
		strcpy(out, cl_InputBuff());
		if('\0' != cl_InputBuff()[0]){ valide=1; }
	} /* valide */
	
	/*
		Ouput:
			A pointer to the data that is a six-size array.
			From this I can read the data.
			I can also deduce information about it like he's length.
	*/

	printf("You input: '%s' of len '%d'\n", out, (int)strlen(out));
	
	free(out);

	return 0;
}

int main(void){
	test_input_output_string();
	
	return 0;
}
