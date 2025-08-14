
/*
DESCR:


INPROUVE:
- Add after the "equality" test
a "similar" test.
This one store in the third array
not the boolean of equality condition
but who much the two number are similar in percent.

*/

/*
https://www.man7.org/linux/man-pages/man2/gettimeofday.2.html


Tuto

13 min, LearningLad, How to Generate Random Numbers in C | Using rand(), srand(), and time() for Unique Sequences:
https://www.youtube.com/watch?v=oXEDMNXzuo4

https://www.cmastery.digibeatrix.com/en/standard-library-functions/c-language-random-generation-methods/

https://thelinuxcode.com/rand-function-in-c-language/

https://www.cmastery.digibeatrix.com/en/standard-library-functions/c-language-random-number-rand-srand/

https://codeforces.com/blog/entry/61587

source code of rand example:
https://stackoverflow.com/questions/1026327/what-common-algorithms-are-used-for-cs-rand

~{
int
rand_r (unsigned int *seed)
{
  unsigned int next = *seed;
  int result;

  next *= 1103515245;
  next += 12345;
  result = (unsigned int) (next / 65536) % 2048;

  next *= 1103515245;
  next += 12345;
  result <<= 10;
  result ^= (unsigned int) (next / 65536) % 1024;

  next *= 1103515245;
  next += 12345;
  result <<= 10;
  result ^= (unsigned int) (next / 65536) % 1024;

  *seed = next;

  return result;
}
}~
*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* srand, rand, RAND_MAX */
#include <stddef.h> /* NULL */
#include <limits.h> /* SCHAR_MAX */
#include <stdbool.h>
#include <string.h> /* memset */
#include <time.h>

/*
~TEST

A) Methode

The test was a function-module.

It have he's encapsulate methodes and values.

It will be varing using a modulare way
for the feature we want to test.

It access function needed for the featureusage.
They could be to access data.

Those function will be call using an interface function
that can call all the version of the function.

Example:
~{
  enum e_module_srand{
  	E_MODULE_SRAND_ONE
  	E_MODULE_SRAND_TWO
  }
  
  void call_Srand(enum e_module_srand _id){
  	switch(_id){
  		case E_MODULE_SRAND_ONE:
  			module_one_Srand();
  			break;
  	
  		case E_MODULE_SRAND_TWO:
  			module_two_Srand();
  			break;
  	}
  }
}~

B) Tests

1) Similitude test

Have two array of same fix-len.
Each are fill with a random number generator process
with the same methode but one after the other.

Using a third array of same len
of type boolean.
Compare each array.
Store the result of equality condition
in this third corresponding index.

Count hte number of time the third array
have a true value in it.

*/

/*
~RANDOM-GLOBAL
*/

/*
Random parameters:
- seed. ( internaly generated from the module local scope )
- rand-return value. ( Set using the module return and get for the call-function return. This emulate the rand function. )
*/

static int buff_rand=0;

void buff_rand_Set(const int _val){
	buff_rand=_val;
}
const int buff_rand_Get(void){
	return buff_rand;
}

static int buff_seed=0;

void buff_seed_Set(const int _val){
	buff_seed=_val;
}
const int buff_seed_Get(void){
	return buff_seed;
}

/*
~MODULES
*/

enum e_module_random{
	E_MODULE_RANDOM_NULL,
	
	E_MODULE_RANDOM_ONE,
	E_MODULE_RANDOM_TWO,
	
	E_MODULE_RANDOM_MAX
};

#define LABEL_LEN 50

const char MODULE_LABEL[E_MODULE_RANDOM_MAX][LABEL_LEN] = {
	"E_MODULE_RANDOM_NULL",
	
	"E_MODULE_RANDOM_ONE",
	"E_MODULE_RANDOM_TWO",
};

void module_random_one_Srand(void);
void module_random_two_Srand(void);

void module_random_CallSrand(enum e_module_random _module_id){
	switch(_module_id){
		case E_MODULE_RANDOM_ONE:
			module_random_one_Srand();
			break;

		case E_MODULE_RANDOM_TWO:
		  module_random_two_Srand();
			break;
	
		default:
			break;
	}
}

void module_random_one_Rand(void);
void module_random_two_Rand(void);

const int module_random_CallRand(enum e_module_random _module_id){
	switch(_module_id){
		case E_MODULE_RANDOM_ONE:
			module_random_one_Rand();
			break;

		case E_MODULE_RANDOM_TWO:
			module_random_two_Rand();
			break;
	
		default:
			break;
	}
	return (const int)buff_rand_Get();
}

/*
~SRAND
*/

static int seed_iteration=0;

void module_random_one_Srand(void){
	int seed=time(NULL)+seed_iteration;
	if(seed_iteration < INT_MAX){ seed_iteration++; }
	else{ seed_iteration=0; }
	buff_seed_Set(seed);
	srand(seed);
}

void module_random_two_Srand(void){
	int seed=time(NULL)+seed_iteration;
	if(seed_iteration < INT_MAX){ seed_iteration++; }
	else{ seed_iteration=0; }
	buff_seed_Set(seed);
	srand(seed);
}

/*
~RAND
*/

void module_random_one_Rand(void){
	int r=0;
	r=rand()%INT_MAX;
	buff_rand_Set(r);
}

void module_random_two_Rand(void){
	int r=0;
	r=rand()%INT_MAX;
	buff_rand_Set(r);
}

/*
~TEST-ZERO ( system test )
*/

void test_zero(void){
	printf("Call: '%s'\n", __FUNCTION__);
	
	const char descr[]=
	"Descr:\n"
	"  Test the function that call each modules\n"
	"  in he's most basic form.\n";

	printf(descr);

	int k=E_MODULE_RANDOM_ONE;
	int kmax=E_MODULE_RANDOM_MAX;
	while(k < kmax){

		/* SETUP */
	
  	enum e_module_random module_id = (enum e_module_random)k;

		printf("Setup: module id: '%d' name '%s'\n", module_id, MODULE_LABEL[(int)module_id]);
	
		/* SEED */

		printf("Seed\n");

		module_random_CallSrand(module_id);
	
		/* RAND */
		
		printf("Generating\n");
	
		int i=0;
		int imax=20;
		while(i < imax){
			int r=module_random_CallRand(module_id);
			printf("i '%d' r '%d'\n", i, r);
			i++;
		}
		
		/* END */
	
		k++;
	}
}

/*
~TEST-ONE ( similitude bettween two iteration )
*/

#define BUFF_MAX 100

static int buff_one[BUFF_MAX];
static int buff_two[BUFF_MAX];
static int buff_three[BUFF_MAX];

void test_one(void){
	printf("Call: '%s'\n", __FUNCTION__);
	
	const char descr[]=
	"Descr:\n"
	"  Two generating with a same module.\n"
	"  Compare if the value for a same iteration are the same.\n";

	printf(descr);

	int k=E_MODULE_RANDOM_ONE;
	int kmax=E_MODULE_RANDOM_MAX;
	while(k < kmax){

		/* SETUP */
	
  	enum e_module_random module_id = (enum e_module_random)k;

		printf("Setup: module id: '%d' name '%s'\n", module_id, MODULE_LABEL[(int)module_id]);
	
		/* SEED */

		printf("Seed\n");

		module_random_CallSrand(module_id);
	
		/* RAND */
		
		printf("Generating\n");
	
		int i=0;
		int imax=BUFF_MAX;
		
		int j=0;
		int jmax=(int)(BUFF_MAX/8);
		
		i=0;
		j=0;
		while(i < imax){
			
			if(j < jmax){ j++; }
			else{ j=0; module_random_CallSrand(module_id); printf("Seed: '%d'\n", buff_seed_Get()); }
			
			int r=module_random_CallRand(module_id);
			buff_one[i]=r;
			printf("i '%d' r '%d'\n", i, r);
			i++;
		} /* i < imax */
		
		i=0;
		j=0;
		while(i < imax){
			
			if(j < jmax){ j++; }
			else{ j=0; module_random_CallSrand(module_id); printf("Seed: '%d'\n", buff_seed_Get()); }
			
			int r=module_random_CallRand(module_id);
			buff_two[i]=r;
			printf("i '%d' r '%d'\n", i, r);
			i++;
		} /* i < imax */
		
		i=0;
		int equality_count=0;
		while(i < imax){
			int one=buff_one[i];
			int two=buff_two[i];
			bool b=(bool)(one == two);
			printf("i '%d'; (one '%d' == two '%d') = b '%d'\n", i, one, two, b);
			
			buff_three[i]=b;
			if( buff_three[i] ){ equality_count++; }
			i++;
		} /* i < imax */
		
		printf("Equality: '%d'/'%d'\n", equality_count, imax);
		
		/* END */
	
		k++;
	} /* k < kmax */
}

int main(void){
	test_zero();
	test_one();
	return 0;
}
