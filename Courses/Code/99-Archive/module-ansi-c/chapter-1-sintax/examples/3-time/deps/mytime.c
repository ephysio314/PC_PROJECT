
/*
gettimeofday examples:

https://stackoverflow.com/questions/7760951/gettimeofday-c-inconsistency
~{
  const int count = 1000;
  timeval tim;

  gettimeofday(&tim, NULL);
  double t1 = 1.0e6 * tim.tv_sec + tim.tv_usec;

  int v;
  for (int i = 0; i < count; ++i)
    v = a(3, 4);           

  gettimeofday(&tim, NULL);
  double t2 = 1.0e6 * tim.tv_sec + tim.tv_usec;
}~
    
https://www.delftstack.com/howto/c/c-timer/

~{
(end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}~

using timespec
~{
float time_diff2(struct timespec *start, struct timespec *end) {
  return (end->tv_sec - start->tv_sec) + 1e-9 * (end->tv_nsec - start->tv_nsec);
}
}~

*/
#include <limits.h> /* SCHAR_MAX */
#include <stddef.h> /* NULL */
#include <sys/time.h>
/*
struct timeval{
	time_t tv_sec; // seconds
	suseconds_t tv_usec; // microseconds
};
gettimeofday()
*/

static long sec_start=0;
static long microsec_start=0;

static long sec=0;
static long microsec=0;

static char t_is_init=0;

char time_IsInit(void){
	return t_is_init;
}

void time_Start(void){
  struct timeval t;
	gettimeofday(&t, NULL);
	
	sec_start = t.tv_sec;
	microsec_start = t.tv_usec;
	sec = t.tv_sec;
	microsec = t.tv_usec;
	
	t_is_init=1;
}
void time_Upd(void){
  struct timeval t;
	gettimeofday(&t, NULL);
	sec = t.tv_sec;
	microsec = t.tv_usec;
}

long time_Sec(void){
	return sec - sec_start;
}
long time_Microsec(void){
	return microsec - microsec_start;
}

float time_Float(void){
 return (float)time_Sec() + 1e-6 * (float)time_Microsec();
}

