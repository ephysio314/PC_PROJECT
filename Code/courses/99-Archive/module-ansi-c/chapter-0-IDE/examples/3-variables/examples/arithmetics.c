
#include <stdio.h> /* printf */

int main(void){
	int x = 9, y = 5;
	printf("'%d' = '%d' '%c' '%d'\n", x + y, x, '+', y);
	printf("'%d' = '%d' '%c' '%d'\n", x - y, x, '-', y);
	printf("'%d' = '%d' '%c' '%d'\n", x * y, x, '*', y);
	
	float fx = (float)x, fy = (float)y;
	printf("'%f' = '%f' '%c' '%f'\n", fx / fy, fx, '/', fy);
	
	return 0;
}
