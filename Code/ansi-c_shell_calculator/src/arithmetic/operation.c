
/*
https://en.cppreference.com/w/c/numeric/math/div.html

https://cplusplus.com/reference/cstdlib/div_t/

typedef struct {
  int quot;
  int rem;
} div_t;
*/

#include <stdlib.h> /* div_t, div */

int _add(int _x, int _y){
	return _x + _y;
}
int _sub(int _x, int _y){
	return _x - _y;
}
int _mult(int _x, int _y){
	return _x * _y;
}
div_t _div(int _x, int _y){
	return div(_x, _y);
}

