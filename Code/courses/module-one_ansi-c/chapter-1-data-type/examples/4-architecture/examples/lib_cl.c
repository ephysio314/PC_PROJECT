
#include <cl.h>
/*
void cl_PrintStr(const char * _val);
void cl_PrintInt(const int _val);
const char * cl_Input(void);
const int cl_IntInput(void);
*/

/*
~TEST-OPERATION
*/

#include <stdio.h> /* printf */

#include <string.h> /* strcmp, strcpy */

enum e_operation_mode{
	E_OPERATION_MODE_NULL,
	
	E_OPERATION_MODE_ADD,
	E_OPERATION_MODE_SUB,
	E_OPERATION_MODE_MULT,
	
	E_OPERATION_MODE_MAX
};

#define LABEL_LEN 25

static const char LABEL_MODE[E_OPERATION_MODE_MAX][LABEL_LEN] = {
	"\0",
	
	"+",
	"-",
	"*",
};

int Operation(enum e_operation_mode _mode, int _x, int _y){
	switch(_mode){
		case '+':
			return _x + _y;
	
		case '-':
			return _x + _y;
	
		case '*':
			return _x + _y;
	}
	
	return 0;
}

char cl_test_operation(void){
	printf("Call: '%s'\n", __FUNCTION__);
	
	char run=1;
	while(run){
	
		char is_valide=0;
		while(is_valide){
		
			/* Propoise to exit or process */
			
			char label_operation[LABEL_LEN] = "Y";
			char label_exit[LABEL_LEN] = "Y";
	
			printf("Action:\n");
			printf("- Operation: '%s'\n", "Y");
			printf("- Exit: '%s'\n", "N");
	
			/* Request */
		
			char ask_mode[LABEL_LEN];
			strcpy(ask_action, cl_Input());
			
			if(0 == strcmp(label_operation, ask_action)){
				is_valide=1;
			}else if(0 == strcmp(label_exit, ask_action)){
				is_valide=1;
				run=0;
			}
		}
		
		/* OPERATION */

		if(run){

			int x;
			int y;
			enum e_operation_mode mode=0;
	
			const int imin=E_OPERATION_MODE_ADD;
			const int imax=E_OPERATION_MODE_MAX;
			int i;
	
			printf("Enter x\n");
			x=cl_IntInput();
	
			printf("Enter y\n");
			y=cl_IntInput();
	
			while(0 == mode){
	
				/* Proposition */
	
				printf("Enter mode:\n");
				i=imin;
				while(i < imax){
					printf("- '%s'\n", LABEL_MODE[i]);
					i++;
				} /* i < imax */
		
				/* Request */
		
				char ask_mode[LABEL_LEN];
				strcpy(ask_mode, cl_Input());
		
				/* validation */
		
				printf("Enter mode:\n");
				i=imin;
				while(i < imax){
					if(0 == strcmp(ask_mode, LABEL_MODE[i])){
						mode=(enum e_operation_mode)i;
					}
					i++;
				} /* i < imax */
		
			} /* 0 == mode */
	
			printf("'%d' = '%d' '%s' '%d'\n", Operation(mode, x, y), x, LABEL_MODE[mode], y);
		
			/* END */
		
			run=0;
		} /* run */
	} /* run */

	return 0;
}

int main(void){
	cl_test_operation();
	return 0;
}
