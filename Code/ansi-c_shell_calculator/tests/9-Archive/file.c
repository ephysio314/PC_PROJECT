
#include <stdio.h> /* FILENAME_MAX */
/* 
FILE*
fopen
fclose
fread
fseek
https://en.cppreference.com/w/c/io/fseek
*/

#include <stdlib.h>
/*
calloc
free
exit
*/

#include <errno.h>

#include <string.h> /* strlen */

static char filename[FILENAME_MAX] = "filename.bin";

int Len(void){
	int len=0;

	FILE*file=fopen(filename, "rb");
	
	/*
	if(NULL == file){
		printf("ERROR:FAIL_OPEN_FILE; line '%d'; error '%s'\n", __LINE__ , strerror(errno));exit(1);
	}
	*/
	
	if(NULL == file){ return 0; }

	while(1){
		char c;
		fread(&c, sizeof(char), 1, file);
		if(EOF == c || '\0' == c){ break; }
		
		#if 1
		fputc(c, stdout);
		#endif
		
		len++;
	}

	fclose(file);

	return len;
}

void Read(void){
	FILE*file=fopen(filename, "rb");

	if(NULL == file){
		printf("ERROR:FAIL_OPEN_FILE; line '%d'; error '%s'\n", __LINE__ , strerror(errno));exit(1);
	}

	while(1){
		char c;
		fread(&c, sizeof(char), 1, file);
		if(EOF == c || '\0' == c){ break; }
		fputc(c, stdout);
	}

	fclose(file);
}

void Write(const char * _val){

	FILE*file;

	/* LOAD CURRENT FILE */

	int old_len = Len() + 1;
	int len = old_len + (int)strlen(_val) + 1;
	char * buff = (char*)calloc(sizeof(char), len);
	
	file=fopen(filename, "rb");

	if(NULL == file){
		printf("ERROR:FAIL_OPEN_FILE; line '%d'; error '%s'\n", __LINE__ , strerror(errno));exit(1);
	}

	int i=0;
	int imax=old_len;
	while(i < imax){
		char c;
		fread(&c, sizeof(char), 1, file);
		buff[i]=c;
		
		#if 1
		printf("buff['%d']='%c'\n", i, c);
		#endif
		
		i++;
	}

	/* PUSH */
	
	int j=0;
	int jmax=(int)strlen(_val)+1;
	while(j < jmax){
		buff[i+j]=_val[j];
		
		#if 1
		printf("buff['%d']=_val['%d']='%c'\n", i+j, j, _val[j]);
		#endif
		
		j++;
	}
	
	fclose(file);
	
	file=fopen(filename, "wb");

	if(NULL == file){
		printf("ERROR:FAIL_OPEN_FILE; line '%d'; error '%s'\n", __LINE__ , strerror(errno));exit(1);
	}
	
	fwrite(buff, sizeof(char), len, file);

	fclose(file);
	
	free(buff);
}

int main(void){

	Write("Hello, World!\n");
	Write("Second.");
	Write(" Third\n");
	
	Read();

	return 0;
}
