
#include <stdio.h> /* printf, getchar */
#include <string.h> /* strlen */
#include <stdbool.h>
#include <limits.h> /* SCHAR_MAX */

#include "src/convert.h"
/*
#define _atoi atoi
void _itoa(int _val, char _targ[]);
bool hc_IsInt(char _val);
*/

static char buff[BUFSIZ]=(char[BUFSIZ]){0};

void cl_BuffReset(void){
	memset(buff, '\0', sizeof(char) * BUFSIZ);
}

char * cl_Buff(void){
	return buff;
}

/*
~Condition
*/

void cl_config_Default(void);

bool cl_BuffIsEmpty(void){
	bool b=0;
	b+=(bool)('\0' == buff[0]);
	return b;
}

static int buff_int_limit=INT_MAX;

void cl_SetBuffIntLimit(int _val){
	buff_int_limit=_val;
}

bool cl_BuffIsInt(void){
	int i=0;
	int imax=BUFSIZ;
	while(i < imax && '\0' != buff[i]){
		if(!hc_IsInt(buff[i]) && (int)_atoi(buff) < buff_int_limit){ return false; }
		i++;
	}
	return true;
}

/*
~Formating

Change the string depanding on the config.
*/

void cl_config_Reset(void);

#define FORMAT_CH_IGNOR_LEN SCHAR_MAX 

static char config_ch_ignor[FORMAT_CH_IGNOR_LEN] = (char[FORMAT_CH_IGNOR_LEN]){'\0'};
static int config_ch_ignor_fill=0;

void cl_config_PushChIgnor(char _ch){
	if(config_ch_ignor_fill < FORMAT_CH_IGNOR_LEN){
		config_ch_ignor[config_ch_ignor_fill]=_ch;
		config_ch_ignor_fill++;
		config_ch_ignor[config_ch_ignor_fill]='\0';
	}
}

void cl_config_PushChIgnorNumbers(void){
	cl_config_PushChIgnor('0');
	cl_config_PushChIgnor('1');
	cl_config_PushChIgnor('2');
	cl_config_PushChIgnor('3');
	cl_config_PushChIgnor('4');
	cl_config_PushChIgnor('5');
	cl_config_PushChIgnor('6');
	cl_config_PushChIgnor('7');
	cl_config_PushChIgnor('8');
	cl_config_PushChIgnor('9');
}

bool cl_InputIsIgnor(char _val){
	if(0 != config_ch_ignor_fill){
		int i=0;
		int imax=FORMAT_CH_IGNOR_LEN;
		while(i < imax && '\0' != config_ch_ignor){
			if(config_ch_ignor[i] == _val){ return true; }
			i++;
		} /* i < imax && '\0' != config_ch_stop */
	}
	return false;
}

#define FORMAT_CH_STOP_LEN 6 

static char config_ch_stop[FORMAT_CH_STOP_LEN] = (char[FORMAT_CH_STOP_LEN]){'\0'};
static int config_ch_stop_fill=0;

void cl_config_PushChStop(char _ch){
	if(config_ch_stop_fill < FORMAT_CH_STOP_LEN){
		config_ch_stop[config_ch_stop_fill]=_ch;
		config_ch_stop_fill++;
		config_ch_stop[config_ch_stop_fill]='\0';
	}
}

bool cl_InputIsStop(char _val){
	if(0 != config_ch_stop_fill){
		int i=0;
		int imax=FORMAT_CH_STOP_LEN;
		while(i < imax && '\0' != config_ch_stop){
			if(config_ch_stop[i] == _val){ return true; }
			i++;
		} /* i < imax && '\0' != config_ch_stop */
	}
	return false;
}

void cl_config_Default(void){

	buff_int_limit=INT_MAX;

	config_ch_stop[0]=0;
	config_ch_stop_fill=0;
}

/*
~Input
*/

void cl_Input(void){
	cl_BuffReset();
	bool keep_pushing=true;
	int i=0;
	int imax=BUFSIZ;
	while(1){
		char c = getchar();
		if(cl_InputIsStop(c)){ keep_pushing=false; }
		if('\n' == c || EOF == c){ break; }
		else if(keep_pushing && !cl_InputIsIgnor(c)){ buff[i]=c; i++; } /* if ignor was true, keep iterating to empty the stream but don't push anymore. True one's */
	}
}

int main(void){
	cl_SetBuffIntLimit(120); /* cl_BuffIsInt() only valide equal or below this value */
	char valide=0;
	while(!valide){
		printf("Enter your age\n");
		cl_Input();
		if(!cl_BuffIsEmpty() && cl_BuffIsInt()){ valide=1; }
	}
	
	printf("Input: '%s'; len: '%d'\n", cl_Buff(), (int)strlen(cl_Buff()));
	
	return 0;
}
