
#include <stdio.h> /* printf */
#include <myadd.h>

int main(void){
	int x = 9, y = 5;
	printf("myadd: '%d' = '%d' '%c' '%d'\n", myadd(x, y), x, '+', y);
	return 0;
}
