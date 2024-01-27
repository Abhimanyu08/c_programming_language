#include <stdio.h>
#include "getl.h"

#define MAXLEN 1000


 int getl(char* s) {

    int i,c;
    for (i = 0; ((c = getchar()) != EOF) && c != '\n'; i++)
	*s++ = c;

    *s++ = '\0';

    return i;

}


