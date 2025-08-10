
#include <stdio.h> /* printf */
#include <arithmetic/operation.h> /* _add, _sub, _mult, _div */

int main(void){
	int x = 5, y = 9;
	
	printf("'%d' = '%d' '%c' '%d'\n", _add(x, y), x, '+', y);
	printf("'%d' = '%d' '%c' '%d'\n", _sub(x, y), x, '-', y);
	printf("'%d' = '%d' '%c' '%d'\n", _mult(x, y), x, '*', y);
	
	float fx = (float)x, fy = (float)y;
	printf("'%f' = '%f' '%c' '%f'\n", _div(fx, fy), fx, '*', fy);
	
	return 0;
}
