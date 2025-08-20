
#include <stdio.h>
/*
FILE*
fopen
fclose
fwrite
fread
EOF
FILENAME_MAX
*/
#include <stdlib.h>
/*
calloc
free
*/
#include <string.h> /* strlen */

char filename[FILENAME_MAX]="build/examples/file.bin";
static FILE*file=NULL;
char * buff=NULL;

void file_Write(const char * _val){
	FILE*file=fopen(filename, "wb");
	if(NULL == file){ printf("ERROR:FILE_FAIL_OPEN: '%s'\n", filename);exit(1); }
	fwrite(_val, sizeof(char), (int)strlen(_val)+1, file);
	fclose(file);
}

int file_Len(void){
	int return_val=0;
	FILE*file=fopen(filename, "rb");
	if(NULL == file){ printf("ERROR:FILE_FAIL_OPEN: '%s'\n", filename);exit(1); }
	while(1){
		char c;
	  fread(&c, sizeof(char), 1, file);
	  if(EOF == c || '\0' == c){ break; }
	  return_val++;
	}
	fclose(file);
	
	return return_val;
}

void file_LoadBuff(void){
  int len=file_Len();
	buff = (char*)calloc(sizeof(char), len + 1);
	
	FILE*file=fopen(filename, "rb");
	if(NULL == file){ printf("ERROR:FILE_FAIL_OPEN: '%s'\n", filename);exit(1); }
	int i=0;
	int imax=len;
	while(1){
		char c;
	  fread(&c, sizeof(char), 1, file);
	  if(EOF == c || '\0' == c || imax <= i){ break; }
	  else{
	  	buff[i]=c;
	    i++;
	  }
	}
	fclose(file);
}

const char * file_GetBuff(void){
	return buff;
}

void file_End(void){
	if(NULL != buff){ free(buff);buff=NULL; }
}

int main(void){

	file_Write("Hello, World!");
	file_LoadBuff();
	printf("Stream: '%s'\n", file_GetBuff());
	
	file_End();
	
	return 0;
}
