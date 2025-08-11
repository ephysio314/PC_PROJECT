
#include <stdio.h> /* printf stdin fgetc */
#include "deps/conversion.h" /* _atoi, _itoa */

int main(void){

	char arg[11] = "14159";
	
	int int_val = _atoi(arg);
	
	printf("From arg '%s' to int_val '%d'\n", arg, int_val);
	
	char str_val[11];
	_itoa(int_val, str_val);
	
	printf("From int_val '%d' to str_val '%s'\n", int_val, str_val);

	return 0;
}
