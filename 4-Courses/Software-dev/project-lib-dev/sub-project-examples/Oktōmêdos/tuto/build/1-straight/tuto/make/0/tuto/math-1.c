
#include <stdio.h> /* printf */

int myadd(int _x, int _y){
	return _x + _y;
}

int main(void){
	int x = 9;
	int y = 5;
	printf("'%d' = '%d' '%c' '%d'\n", myadd(x, y), x, '+', y);
	return 0;
}
