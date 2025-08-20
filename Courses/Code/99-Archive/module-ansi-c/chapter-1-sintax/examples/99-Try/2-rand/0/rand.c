
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
#include <sys/time.h>
/*
struct timeval{
	time_t tv_sec; // seconds
	suseconds_t tv_usec; // microseconds
};
gettimeofday()
*/

/*
~UNIT-TEST
*/

void out_rand_one(void){
	printf("Call: '%s'\n", __FUNCTION__);

	int i=0;
	int imax=50;
	while(i < imax){
		printf("i '%d', r '%d'\n", i, rand());
		i++;
	}
}

void test_one(void){

	printf("random val from '%d' to '%d'\n", 0, RAND_MAX);
	
	out_rand_one();
	out_rand_one();
}


/*
~ABSTRACTION
*/

static struct timeval t_start={0, 0};
static struct timeval t={0, 0};
static char t_is_init=0;

char time_IsInit(void){
	return t_is_init;
}

void time_Start(void){
	gettimeofday(&t_start, NULL);
	gettimeofday(&t, NULL);
	t_is_init=1;
}
void time_Upd(void){
	gettimeofday(&t, NULL);
}

int time_Sec(void){
	return t.tv_sec - t_start.tv_sec;
}
int time_Microsec(void){
	return t.tv_usec - t_start.tv_usec;
}

static int rand_buff[SCHAR_MAX] = (int[SCHAR_MAX]){0};
static int rand_buff_fill=0;

void rand_Load(void){
	if(!time_IsInit()){ time_Start(); while(time_Sec() < 1 && time_Microsec() < 25){ time_Upd(); } }
	time_Upd();
	
	char need_seed=0;
	int j=10;
	int imax=SCHAR_MAX;
	while(rand_buff_fill < imax){
		if(j < 10){ j++; }
		else{ j=0; need_seed=1; }
		
		if(need_seed){ time_Upd(); srand(time_Microsec() + rand_buff_fill); need_seed=0; }
		
		rand_buff[rand_buff_fill]=rand()%INT_MAX + 1;
		rand_buff_fill++;
	}
}

int rand_Pop(void){
	int return_val=0;
	if(rand_buff_fill <= 0){ rand_Load(); }
	return_val = rand_buff[rand_buff_fill];
	rand_buff_fill--;
	return return_val;
}

void abstraction_out_rand_one(void){
	int i=0;
	int imax=200;
	while(i < imax){
		printf("i '%d': rand '%d'\n", i, rand_Pop());
		i++;
	}
}

void test_abstraction_one(void){
	printf("Call: '%s'\n", __FUNCTION__);

	abstraction_out_rand_one();
	abstraction_out_rand_one();
}

int main(void){

	test_one();
	
	test_abstraction_one();
	
	return 0;
}
