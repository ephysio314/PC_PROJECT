
#include <stdio.h> /* printf */
#include <limits.h> /* INT_MAX */

#include <mytime.h>
/*
char time_IsInit(void);
void time_Start(void);
void time_Upd(void);
long time_Sec(void);
long time_Microsec(void);
float time_Float(void);
*/

void foo(void){
	int i=0;
	int imax=INT_MAX;
	while(i < imax){ i++; }
}

int main(void){
  time_Start();
  time_Upd();
	float start=time_Float();
	foo();
  time_Upd();
	float end=time_Float();
	printf("start '%f; end '%f; total '%f.\n", start, end, end-start);
	return 0;
}
