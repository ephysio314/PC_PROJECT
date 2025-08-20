
#include <stdio.h> /* printf */

#include <mylib.h>
/*
const char * _input(const char * _msg);
void _print(const char * _val);
*/

int one(void){
	printf("Call: '%s'\n", __FUNCTION__);

	char str[BUFSIZ] = {0};
	strcpy(str, _input("Enter a sentence about you\n"));
	_print("You sentence was: ");
	_print(str);
	_print("\n");

	return 0;
}

int main(void){
	one();
	return 0;
}
