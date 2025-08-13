
#include <stdio.h> /* printf */

enum e_operation_mode{
	E_OPERATION_MODE_NULL,
	E_OPERATION_MODE_ADD = '+',
	E_OPERATION_MODE_SUB = '-',
	E_OPERATION_MODE_MULT = '*'
};

struct CmdOperation{
	enum e_operation_mode mode;
	
	int x;
	int y;
};

int Add(int _x, int _y){
	return _x + _y;
}
int Sub(int _x, int _y){
	return _x - _y;
}
int Mult(int _x, int _y){
	return _x * _y;
}

int operation_Call(struct CmdOperation _cmd){
	switch(_cmd.mode){
		case E_OPERATION_MODE_ADD:
			return Add(_cmd.x, _cmd.y);
			break;
	
		case E_OPERATION_MODE_SUB:
			return Sub(_cmd.x, _cmd.y);
			break;
	
		case E_OPERATION_MODE_MULT:
			return Mult(_cmd.x, _cmd.y);
			break;
	
	}
	return 0;
}

void operation_CallPrint(struct CmdOperation _cmd){
	printf("'%d' = '%d' '%c' '%d'\n", operation_Call(_cmd.mode, _cmd.x, _cmd.y), _cmd.x, (char)_cmd.mode, _cmd.y);
}

int main(void){

	/* SETUP */

	struct CmdOperation cmd;
	cmd.x = 5;
	cmd.y = 9;
	cmd.mode = E_OPERATION_MODE_NULL;
	
	/* PROCESS */
	
	cmd.mode=E_OPERATION_MODE_ADD;
	operation_CallPrint(cmd);
	
	cmd.mode=E_OPERATION_MODE_SUB;
	operation_CallPrint(cmd);
	
	cmd.mode=E_OPERATION_MODE_MULT;
	operation_CallPrint(cmd);
	
	return 0;
}
