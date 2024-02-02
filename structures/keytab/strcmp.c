#include "stringcompare.h"
int stringcompare(char* s, char* t) {
    //return 0 if equal, -1 if s < t and 1 if s > t
    
    for (;*s == *t; s++, t++)
	if (*s == '\0')
	    return 0;


    return *s - *t;


}
