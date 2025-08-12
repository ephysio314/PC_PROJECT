
#include <limits.h> /* INT_MAX */

#include <string.h> /* memset */

#include <stdio.h>
/*
stdout
fputc
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

int str_Len(const char * _val){
	if(NULL != _val){ 
		int i=0;
		int imax=INT_MAX;
		while(i < imax){
			if('\0' == _val[i]){ return i; }
			i++;
		} /* i < imax */
	} /* NULL != _val */
	return 0;
}

void str_Cpy( const char * _val, char * _targ){
	int val_len = str_Len(_val);
	if(0 != val_len){
		int i=0;
		int imax=val_len;
		while(i < imax && '\0' != _val[i]){
			_targ[i]=_val[i];
			i++;
		}
	}
}

/*
~VIEW
*/

void str_Print(const char * _val){
	int i=0;
	int imax=str_Len(_val);
	while(i < imax){
		fputc(_val[i], stdout);
		i++;
	}
}

/*
~BUFF
*/

char * buff=NULL;

void str_ResetBuff(void);

void str_CreatBuff(int _len){
	if(NULL != buff){ str_ResetBuff(); }
	buff = (char*)malloc(sizeof(char) * (_len + 1));
}

void str_FreeBuff(void){
	if(NULL != buff){ free(buff);buff=NULL; }
}

void str_ResetBuff(void){
	if(NULL != buff){
		memset(buff, '\0', sizeof(char) * (str_Len(buff)+1));
	}
}

const char * str_GetBuff(void){
	return buff;
}

int str_BuffLen(void){
	return (int)str_Len(buff);
}

/*
~CONTROL
*/

/*
Buffering control
https://www.gnu.org/software/libc/manual/html_node/Controlling-Buffering.html
*/

const char * str_Input(void){
	str_ResetBuff();
	int i=0;
	int imax=INT_MAX;
	while(1){
		char c = fgetc(stdin);
		if(EOF == c || '\n' == c){ break; }
		else if(i < imax){ buff[i] = c; i++; }
	}
	return buff;
}

/*
~STREAM
*/

char filename[FILENAME_MAX]="build/examples/file.bin";
static FILE*file=NULL;

void file_Write(const char * _val){
	FILE*file=fopen(filename, "wb");
	fwrite(_val, sizeof(char), (int)str_Len(_val)+1, file);
	fclose(file);
}

int file_Len(void){
	int return_val=0;
	FILE*file=fopen(filename, "rb");
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
	str_CreatBuff(len);
	
	FILE*file=fopen(filename, "rb");
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

