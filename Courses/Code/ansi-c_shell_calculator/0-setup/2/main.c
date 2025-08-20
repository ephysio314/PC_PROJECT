
#include <stdio.h> /* printf */

#include <mylib.h>
/*
module_one:
int add(int _x, int _y);
int sub(int _x, int _y);
int mult(int _x, int _y);
*/

int one(void){
	printf("Call: '%s'\n", __FUNCTION__);

	printf("Hello, World!\n");

	return 0;
}

int two(void){
	printf("Call: '%s'\n", __FUNCTION__);

	int x=9;
	int y=5;
	
	printf("'%d' = '%d' '%c' '%d'\n", add(x, y), x, '+', y);
	printf("'%d' = '%d' '%c' '%d'\n", sub(x, y), x, '-', y);
	printf("'%d' = '%d' '%c' '%d'\n", mult(x, y), x, '*', y);

	return 0;
}

int main(void){
	one();
	two();
	return 0;
}
