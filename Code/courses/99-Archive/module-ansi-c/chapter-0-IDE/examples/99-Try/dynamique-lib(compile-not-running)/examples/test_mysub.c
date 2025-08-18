
#include <stdio.h> /* printf */
#include <mysub.h>

int main(void){
	int x = 9, y = 5;
	printf("mysub: '%d' = '%d' '%c' '%d'\n", mysub(x, y), x, '-', y);
	return 0;
}
