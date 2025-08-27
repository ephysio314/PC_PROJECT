
#include <stdio.h> /* printf */

#include <mymath.h>

int main(void){
	int x = 9;
	int y = 5;
	printf("'%d' = '%d' '%c' '%d'\n", myadd(x, y), x, '+', y);
	return 0;
}
