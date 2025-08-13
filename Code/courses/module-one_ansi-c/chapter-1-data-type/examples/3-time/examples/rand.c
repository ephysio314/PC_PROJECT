
/*
https://www.man7.org/linux/man-pages/man2/gettimeofday.2.html


Tuto

13 min, LearningLad, How to Generate Random Numbers in C | Using rand(), srand(), and time() for Unique Sequences:
https://www.youtube.com/watch?v=oXEDMNXzuo4




*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* srand, rand, RAND_MAX */
#include <stddef.h> /* NULL */
#include <limits.h> /* SCHAR_MAX */
#include <stdbool.h>
#include <string.h> /* memset */

#include <mytime.h>
/*
char time_IsInit(void);
void time_Start(void);
void time_Upd(void);
long time_Sec(void);
long time_Microsec(void);
float time_Float(void);
*/

/*
~DEBUG:
	A) Pair array buffer
	
	We have two fix-size array integer of same size.
	They will be fill using the speudorandom number generater
	each by one process.
	
	Meaning that we call the generator to fill one.
	And we call a second time the generator to fill the second.
	
	In a third integer array with the same size than the others.
	
	We iteratate the two array and compare if was the same value.
	If was we store one in the third, else zero.
	
	We ouput in the shell who many are similar.
	
	Optionnal:
	  And in a text file the third array result.
	 
*/

/*
~DEBUG
*/

bool buff_one_and_two_IsFill(void);
bool buff_three_IsFill(void);
int buff_GetId(void);
void buff_Reset(void);
bool buff_Push(const char _val);
bool buff_three_Upd(void);
int buff_count_GetSimilar(void);
bool buff_three_Print(void);

#define BUFF_MAX 100

static int buff_id_select=0;

int buff_one[BUFF_MAX] = (int[BUFF_MAX]){0};
int buff_one_fill=0;

int buff_two[BUFF_MAX] = (int[BUFF_MAX]){0};
int buff_two_fill=0;

bool buff_three[BUFF_MAX] = (bool[BUFF_MAX]){0};
int buff_three_fill=0;

void buff_Reset(void){
	memset(buff_one, 0, sizeof(int) * BUFF_MAX);
	buff_one_fill=0;
	
	memset(buff_two, 0, sizeof(int) * BUFF_MAX);
	buff_two_fill=0;
	
	memset(buff_three, 0, sizeof(bool) * BUFF_MAX);
	buff_three_fill=0;
}

int buff_GetId(void){
	return buff_id_select;
}

bool buff_one_and_two_IsFill(void){
  return (bool)(BUFF_MAX == buff_one_fill && BUFF_MAX == buff_two_fill);
}
bool buff_three_IsFill(void){
  return (bool)(BUFF_MAX == buff_three_fill);
}

bool buff_Push(const char _val){
	switch(buff_id_select){
		case 0:
			if(buff_one_fill < BUFF_MAX){
		    buff_one[buff_one_fill]=_val;
				buff_one_fill++;
				break;
			}else{
				buff_id_select++;
			}
			
		case 1:
			if(buff_two_fill < BUFF_MAX){
		    buff_two[buff_two_fill]=_val;
				buff_two_fill++;
			}else{
				buff_id_select++;
			}
			break;
		case 2:
			buff_three_Upd();
			break;
			
		default:
			return 1;
	}
	return 0;
}

bool buff_three_Upd(void){
	if(!buff_one_and_two_IsFill()){
		printf("Warning: Buff one and two is not fill!\n");return 1;
	}

	int i=0;
	int imax=BUFF_MAX;
	while(i < imax){
		buff_three[i] = (bool)(buff_one[i] == buff_two[i]);
		buff_three_fill++;
		i++;
	}

	return 0;
}

int buff_count_GetSimilar(void){
	if(BUFF_MAX != buff_three_fill-1){ return -1; }
	
	buff_three_Upd();
	
	int return_val=0;
	
	int i=0;
	int imax=BUFF_MAX;
	while(i < imax){
		buff_three[i] = (bool)(buff_one[i] == buff_two[i]);
		i++;
	}
	return return_val;
}

bool buff_three_Print(void){
	buff_three_Upd();
	if(!buff_three_IsFill()){
		return 1;
	}

	int i=0;
	int imax=BUFF_MAX;
	while(i < imax){
		printf("buff_three['%d']='%d'", i, buff_three[i]);
		i++;
	}
	
	int similar_count = buff_count_GetSimilar();
	if(-1 == buff_three_Print()){ printf("Warning: fail to call buff_count_GetSimilar!\n"); return 1; }
	printf("Similar: '%d'\n", similar_count);

	return 0;
}

/*
~UNIT-TEST
*/

void out_rand_one(void){
	printf("Call: '%s'\n", __FUNCTION__);
	int i;
	
	buff_Reset();

	i=0;
	printf("buff id '%d'\n", buff_GetId());
	while(0 == buff_GetId()){
		if(BUFF_MAX <= i){ printf("Loop using id break because i edge reach\n");break; }
		int r=rand();
		buff_Push(r);
		printf("i '%d', r '%d'\n", i, r);
		i++;
	}
	
	i=0;
	printf("buff id '%d'\n", buff_GetId());
	while(1 == buff_GetId()){
		if(BUFF_MAX <= i){ printf("Loop using id break because i edge reach\n");break; }
		int r=rand();
		buff_Push(r);
		printf("i '%d', r '%d'\n", i, r);
		i++;
	}
	
	printf("buff id '%d'\n", buff_GetId());
	if(0 != buff_three_Print()){ printf("Warning: fail to call buff_three_Print!\n"); }
}

void test_one(void){

	printf("random val from '%d' to '%d'\n", 0, RAND_MAX);
	
	out_rand_one();
}

int main(void){
	test_one();
	return 0;
}
