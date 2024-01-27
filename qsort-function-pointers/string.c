#include "string.h"
#include <stdlib.h>

void strcopy(char *s, char *t) {
    
    while (*t++ = *s++)
	;
}


int strcompare(char *s, char* t) {

    for (;*s == *t; s++, t++)
	if (*s == '\0')
	    return 0;

    return *s - *t;
}


int numcompare(char *s, char* t) {
    
    double v1, v2;

    v1 = atof(s);
    v2 = atof(t);


    if (v1 < v2)
	return -1;
    else if (v1 > v2)
	return 1; 
    else
	return 0;

}
