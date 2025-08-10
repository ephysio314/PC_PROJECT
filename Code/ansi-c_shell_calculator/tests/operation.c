
#include <stdio.h> /* printf */
#include <arithmetic/operation.h>

int main(void){
	int x = 5, y = 9;
	div_t div_result;
	
	float fx, fy;
	float float_div_result;
	
	printf("'%d' = '%d' '%c' '%d'\n", _add(x, y), x, '+', y);
	printf("'%d' = '%d' '%c' '%d'\n", _sub(x, y), x, '-', y);
	printf("'%d' = '%d' '%c' '%d'\n", _mult(x, y), x, '*', y);
	
	div_result = _div(x, y);
	printf("'%d'.'%d' = '%d' '%c' '%d'\n", div_result.quot , div_result.rem , x, '/', y);
	
	fx = (float)x;
	fy = (float)y;
	float_div_result = fx/fy;
	printf("'%f' = '%f' '%c' '%f'\n", float_div_result , fx, '/', fy);
	
	x = 10;
	y = 3;
	div_result = _div(x, y);
	printf("'%d'.'%d' = '%d' '%c' '%d'\n", div_result.quot , div_result.rem , x, '/', y);
	
	fx = (float)x;
	fy = (float)y;
	float_div_result = fx/fy;
	printf("'%f' = '%f' '%c' '%f'\n", float_div_result , fx, '/', fy);
	
	
	return 0;
}
