
#include <stdio.h> /* printf */
#include <limits.h> /* INT_MAX */

#include <data-type/conversion.h> /* _itoa _atoi */
 
int main(void){

	printf("Test: atoi\n");

  printf("%d\n", _atoi(" -123junk"));
  printf("%d\n", _atoi(" +321dust"));
  printf("%d\n", _atoi("0"));
  printf("%d\n", _atoi("0042")); /* treated as a decimal number with leading zeros */
  printf("%d\n", _atoi("0x2A")); /* only leading zero is converted discarding "x2A" */
  printf("%d\n", _atoi("junk")); /* no conversion can be performed */
  printf("%d\n", _atoi("9999999999999")); /* UB: out of range of int */
  
  printf("Test: itoa\n");
  
  int x = 0;
  char int_buff[11] = {0};
  
  x = 9;
  _itoa(x, int_buff);
  printf("int: '%d'; str: '%s'\n", x, int_buff);

  x = x * -1;
  _itoa(x, int_buff);
  printf("int: '%d'; str: '%s'\n", x, int_buff);

  x = INT_MAX;
  _itoa(x, int_buff);
  printf("int: '%d'; str: '%s'\n", x, int_buff);

	return 0;
}
