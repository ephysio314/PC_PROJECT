
#include <stdio.h> /* FILENAME_MAX */
#include <stdlib.h>

#include <string.h> /* strlen */

const char filename[FILENAME_MAX] = "data.bin";
FILE*file = NULL;
char buf[BUFSIZ] = (char[BUFSIZ]){0};

void Reset(void){
	if(NULL != file){
		memset(buf, '\0', sizeof(char) * BUFSIZ);
  	setbuf(file, buf);
  }
}

void Write(const char * _val){
	int len = (int)strlen(_val);	
		
	file=fopen(filename, "wb");
	Reset();
	fwrite(_val, sizeof(char), len, file);
	fclose(file);
}

const char * Read(void){
	#if 0
	/* Not needed because we use "setbuf" */
	file=fopen(filename, "rb");
	fread(buf, sizeof(char), (int)strlen(buf), file);
	fclose(file);
	#endif

	return buf;
}

int main(void){

	if(1){
		printf("Do nothing and Output: '%s'\n", Read());
	}
	
	if(1){
		const char * val = "Hello, World!";
    Write(val);
		printf("Wtire and Output: '%s'\n", Read());
	}

	if(1){
		Reset();
		printf("Reset and Output: '%s'\n", Read());
	}

	return 0;
}
