
#include <stdio.h> /* printf, getchar */

int main(void){
	char valide=0;
	while(!valide){
		printf("Press enter...");
		char c=getchar();
		if('\n' == c){ valide=1; }
	}
	return 0;
}
