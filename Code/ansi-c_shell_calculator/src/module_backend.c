
#include <stdio.h> /* FILENAME_MAX, fopen, fclose, fwrite */
#include <limits.h> /* INT_MAX */

static char backend_filename[FILENAME_MAX] = {0};

int backendMin(void){
	return 255;
}
int backendMax(void){
	return INT_MAX;
}

void backendPushFront(const char * _input){

}

void backendErase(void){
	
}

