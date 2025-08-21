
#include <stdbool.h>

char * _input(const char * _msg);

void _print(const char * _val);

/*
~int conversion
*/

#include <stdlib.h> /* atoi, itoa */

#define _atoi atoi

void _itoa(int _val, char _targ[]);

bool _isi(char _val);
bool _strisi(const char * _val);

