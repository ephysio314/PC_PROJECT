
#include <stdio.h> /* stdout, fputc */
#include <limits.h> /* INT_MAX */

#include <string.h> /* memset */

/*
Buffering control
https://www.gnu.org/software/libc/manual/html_node/Controlling-Buffering.html
*/

static char buf[BUFSIZ] = (char[BUFSIZ]){0};
static int buf_fill=0;

int str_GetBuffSize(void){
	return BUFSIZ;
}

void str_ResetBuf(void){
	memset(buf, '\0', sizeof(char) * BUFSIZ);
	buf_fill=0;
}

const char * str_GetBuf(void){
	return buf;
}

void str_PushBuf(const char _val){
	if(buf_fill < BUFSIZ){ buf[buf_fill]=_val; buf_fill++; }
}

