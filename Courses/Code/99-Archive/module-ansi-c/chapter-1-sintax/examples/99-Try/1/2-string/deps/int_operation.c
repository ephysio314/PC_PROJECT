
#include "macro.h"

#include <stdio.h> /* printf */

int _add(int _x, int _y){
	return _x + _y;
}
int _sub(int _x, int _y){
	return _x - _y;
}
int _mult(int _x, int _y){
	return _x * _y;
}

int int_GetOperation(struct int_CmdOperation _cmd){
	int return_val=0;
	
	switch(_cmd.mode){
		case '+':
			return_val = _add(_cmd.x, _cmd.y);
			break;
	
		case '-':
			return_val = _sub(_cmd.x, _cmd.y);
			break;

		case '*':
			return_val = _mult(_cmd.x, _cmd.y);
			break;
			
		default:
			return_val = 0;
			break;
	}
	
	return return_val;
}

void int_PrintOperation(struct int_CmdOperation _cmd){
	printf("'%d; = '%d' '%c' '%d'\n", int_GetOperation(_cmd), _cmd.x, _cmd.mode, _cmd.y);
}

