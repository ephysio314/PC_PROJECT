
#include <stdio.h> /* printf */
#include <int.h> /* struct int_CmdOperation, int_GetOperation, int_PrintOperation, _atoi, _itoa */

int main(void){
	struct int_CmdOperation cmd;
	
	int x = 9;
	int y = 5;
	
	char strx[11];
	char stry[11];
	
	_itoa(x, strx);
	_itoa(y, stry);
	
	cmd.x = _atoi(strx);
	cmd.y = _atoi(stry);
	
	cmd.mode = '+';
	int_PrintOperation(cmd);
	
	cmd.mode = '-';
	int_PrintOperation(cmd);
	
	cmd.mode = '*';
	int_PrintOperation(cmd);
	
	return 0;
}
