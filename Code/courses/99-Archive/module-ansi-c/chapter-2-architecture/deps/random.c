
#include <limits.h> /* INT_MAX, UCHAR_MAX */

#include <mytime.h>

static int rand_max=INT_MAX;

static int seed_iteration=0;

void random_Srand(void){
	if(!time_IsInit()){ time_Start(); }
	time_Upd();

	unsigned int seed=time_Sec()+time_Microsec()+seed_iteration;
	if(seed_iteration < (int)(INT_MAX/2)){ seed_iteration++; }
	else{ seed_iteration=0; }
	
	buff_seed_Set(seed);
	srand(seed);
}

void random_SetRandMax(const int _val){
	rand_max=_val;
}

const int random_Rand(void){
	int r=0;
	r=rand()%rand_max;
	return (const int)r;
}

/*
~STACK
*/

#define RANDOM_STACK_MAX UCHAR_MAX

static int random_stack[RANDOM_STACK_MAX] = (int[RANDOM_STACK_MAX]){0};
static int random_stack_fill=0;

void random_stack_Fill(void){
	int i=0;
	int imax=RANDOM_STACK_MAX;
	int j=0;
	int jmax=(int)(RANDOM_STACK_MAX/8);
	while(i < imax){
		if(j < jmax){ j++; }
		else{ j=0; random_Srand(); }
		
		random_stack[i]=random_Rand();
		random_stack_fill++;
		i++;
	}
}

const int random_stack_Pop(void){
	if(random_stack_fill <= 0){ random_stack_Fill(); }

	const int return_val=random_stack[random_stack_fill];
	random_stack_fill--;
	
	return (const int)return_val;
}

