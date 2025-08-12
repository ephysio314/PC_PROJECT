
#include <stdio.h> /* stdout, fputc */
#include <limits.h> /* INT_MAX */

#include <string.h> /* memset */

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
~CONTROL
*/

/*
Buffering control
https://www.gnu.org/software/libc/manual/html_node/Controlling-Buffering.html
*/

static char buf[BUFSIZ] = (char[BUFSIZ]){0};

int str_GetBuffSize(void){
	return BUFSIZ;
}

void str_SetBuffStream(FILE*_stream){

}

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

const char * str_GetInputBuf(void){
	return buf;
}

