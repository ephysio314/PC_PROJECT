
#include <cl.h>
/*
void cl_PrintStr(const char * _val);
void cl_PrintInt(const int _val);
const char * cl_Input(void);
const int cl_IntInput(void);
*/

#include <stdio.h> /* printf */

#include <string.h> /* strcmp, strcpy */

#define LABEL_LEN 25


/*
~DESCR:

Use mode and modules to test <cl.h>.

mode are possible process in response
to a request.

Modules are separate parts of the test.

The user can do one request from a list.
Will be call the corresponding mode.

Some mode are a serie of function.
Some function are asking the user
to input value using "cl_Input" or "cl_IntInput".
Those will be call using a command setup by the mode
for this step.
It will contain a message-id and member-variables
to the condition.

Example:
  If ask a number in a range, specify the minimum and maximum.
  If ask one number from a list, specify the list.

Each methodes that ask an input to the user

*/

enum e_mode{
	E_MODE_NULL,
	
	E_MODE_EXIT, /* Interupt the main-loop */
	
	E_MODE_OPERATION_GET_RESULT, /* Use the current x and y and the select operation type to output the result. */
	
	E_MODE_MAX /* Who many modes, null include. */
};

/*
~MODE_INPUT
	Mode that ask an input to the user.
*/

enum e_mode_input{
	E_MODE_NULL,
	
	E_MODE_INPUT_OPERATION_X, /* Ask the user a new x integer */
	E_MODE_INPUT_OPERATION_Y, /* Ask the user a new y integer */
	E_MODE_INPUT_OPERATION_TYPE, /* Ask the user a type of operation from a list */
	
	E_MODE_MAX /* Who many modes, null include. */
};

enum e_operation{
	E_OPERATION_NULL,
	
	E_OPERATION_ADD,
	E_OPERATION_SUB,
	E_OPERATION_MULT,

	E_OPERATION_MAX
};

const char OPERATION_TYPE_LABEL[E_OPERATION_MAX][LABEL_LEN]={
	"null",
	
	"+",
	"-",
	"*"
};

#define INPUT_MODE_MSG_MAX 255
char mode_input_msg_buff[INPUT_MODE_MSG_MAX] = {0};

const char * mode_input_GetMsg(enum e_mode_input _mode){
	strcpy(mode_input_msg_buff, "\0");

	switch(_mode){
		case E_MODE_INPUT_OPERATION_X:
			strcpy(mode_input_msg_buff, "Enter a new value for x\n");
			break;
	
		case E_MODE_INPUT_OPERATION_Y:
			strcpy(mode_input_msg_buff, "Enter a new value for y\n");
			break;
			
		case E_MODE_INPUT_OPERATION_TYPE:
			strcpy(mode_input_msg_buff, "Select an operation type amoung:\n");
			
			int i=1;
			int imax=E_OPERATION_MAX;
			while(i < imax){
				char str[50]={0};
				strcpy(str, "- ");
				strcat(str, OPERATION_TYPE_LABEL[i]);
				strcat(str, "\n");
				
				strcat(mode_input_msg_buff, str);
				
				i++;
			}
			break;
	}

	return mode_input_msg_buff;
}

struct mode_input_Val{
	int x;
	int y;

	char operation_type_label[LABEL_LEN];
};

static struct mode_inputVal mode_input_val = (struct mode_input_Val){0};

void mode_input_Process(enum e_mode_input _mode){
	switch(_mode){
		case E_MODE_INPUT_OPERATION_X:
			printf("%s\n", mode_input_GetMsg(_mode));
			mode_input_val.x=cl_IntInput();
			break;
	
		case E_MODE_INPUT_OPERATION_Y:
			printf("%s\n", mode_input_GetMsg(_mode));
			mode_input_val.y=cl_IntInput();
			break;
			
		case E_MODE_INPUT_OPERATION_TYPE:
		
			char valide=0;
			while(!valide){
				printf("%s\n", mode_input_GetMsg(_mode));
			
				char label[LABEL_LEN]={0};
				strcpy(label, cl_Input());
				
				int i=1;
				int imax=E_OPERATION_MAX;
				while(i < imax){
					if(0 == strcmp(OPERATION_TYPE_LABEL[i], label)){ valide=1; }
					i++;
				}
				
				if(valide){ strcpy(mode_input_val.operation_type_label, label); }
			}
			break;
	}

	return input_mode_msg_buff;
}

/*
~Modes
*/

void 

/*
~TEST-OPERATION
*/


int main(void){
	cl_test_operation();
	return 0;
}
