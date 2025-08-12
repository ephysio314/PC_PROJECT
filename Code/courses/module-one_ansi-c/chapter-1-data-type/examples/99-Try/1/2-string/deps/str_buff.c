
#include <stdio.h> /* BUFSIZ */

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

const char * str_GetInputBuf(void){
	return buf;
}

void str_PushBuf(char _val){
	if(buf_fill < BUFSIZ){
		buf[buf_fill-1]=_val;
		buf_fill++;
	}
}

