
/*
https://www.man7.org/linux/man-pages/man2/gettimeofday.2.html
*/

#include <stdio.h> /* printf */
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
	
	char need_seed=1;
	int j=0;
	int imax=SCHAR_MAX;
	while(rand_buff_fill < imax){
		if(j < 10){ j++; }
		else{ j=0; need_seed=1; }
		
		if(need_seed){ time_Upd(); srand(time_Sec() * time_Microsec() + rand_buff_fill); need_seed=0; }
		
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

int main(void){
	int i=0;
	int imax=200;
	while(i < imax){
		printf("i '%d': rand '%d'\n", i, rand_Pop());
		i++;
	}
	return 0;
}
