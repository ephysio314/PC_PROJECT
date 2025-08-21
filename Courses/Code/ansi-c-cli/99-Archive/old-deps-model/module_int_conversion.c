
#include <stdbool.h>

#include <string.h> /* strlen */
 
 /* reverse:  reverse string s in place */
void reverse(char _targ[]){
  int i, j;
  char c;
 
  for (i = 0, j = strlen(_targ)-1; i<j; i++, j--) {
    c = _targ[i];
    _targ[i] = _targ[j];
    _targ[j] = c;
  }
}
 
void _itoa(int _val, char _targ[]){
  int i, sign;
 
  if ((sign = _val) < 0){  /* record sign */
    _val = -_val;          /* make n positive */
  }
  i = 0;
  do {       /* generate digits in reverse order */
    _targ[i++] = _val % 10 + '0';   /* get next digit */
  } while ((_val /= 10) > 0);     /* delete it */
  if (sign < 0){
    _targ[i++] = '-';
  }
  _targ[i] = '\0';
  reverse(_targ);
}

bool _isi(char _val){
	switch(_val){
		case '0':
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':
			break;
	
		default:
			return false;
	}
	return true;
}

bool _strisi(const char * _val){
	int i=0;
	int imax=(int)strlen(_val)-1;
	while(i < imax){
		if(!_isi(_val[i])){ return false; }
		i++;
	}
	return true;
}


