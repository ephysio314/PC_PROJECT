
#include <stdio.h> /* printf */
#include <string.h> /* strlen, strcpy */

#include <mylib.h>
/*
const char * _input(const char * _msg);
void _print(const char * _val);
void _itoa(int _val, char _targ[]);
bool _isi(char _val);
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

int two(void){
	printf("Call: '%s'\n", __FUNCTION__);
	char * str=NULL;
	while(1){
		str=_input("Enter your age\n");
		if(_strisi(str)){ break; }
	}
	_print("You age was: ");
	_print(str);
	_print("\n");
	
	_print("Your age multiply by four: ");
	int val=_atoi(str) * 4;
	char ibuf[11]={0};
	_itoa(val, ibuf);
	_print(ibuf);
	_print("\n");
	
	return 0;
}

int main(void){
	one();
	two();
	return 0;
}
