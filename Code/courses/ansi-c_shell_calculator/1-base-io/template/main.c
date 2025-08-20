
#include <stdio.h> /* printf */

#include <mylib.h>
/*
Module one
int _add(int _x, int _y);
int _sub(int _x, int _y);
int _mult(int _x, int _y);

Module two
float f_add(float _x, float _y);
float f_sub(float _x, float _y);
float f_mult(float _x, float _y);
float f_div(float _x, float _y);

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
	
	printf("'%d' = '%d' '%c' '%d'\n", _add(x, y), x, '+', y);
	printf("'%d' = '%d' '%c' '%d'\n", _sub(x, y), x, '-', y);
	printf("'%d' = '%d' '%c' '%d'\n", _mult(x, y), x, '*', y);

	return 0;
}

int three(void){
	printf("Call: '%s'\n", __FUNCTION__);

	float x=3.141;
	float y=4.0;
	
	printf("'%f' = '%f' '%c' '%f'\n", f_add(x, y), x, '+', y);
	printf("'%f' = '%f' '%c' '%f'\n", f_sub(x, y), x, '-', y);
	printf("'%f' = '%f' '%c' '%f'\n", f_mult(x, y), x, '*', y);

	printf("'%f' = '%f' '%c' '%f'\n", f_div(x, y), x, '/', y);

	return 0;
}

int main(void){
	one();
	two();
	three();
	return 0;
}
