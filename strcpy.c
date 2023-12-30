#include "strcpy.h"
void stringcopy(char* source, char* target) {
    
    while (*target++ = *source++) 
	;
    

}

int stringcmp(char* s, char* t){
    
    //if s is lexicographically smaller than t return -1
    //if s is lexicographically equal to t return 0 
    //if s is lexicographically larger than t return 1
    
    for (;*s == *t; s++, t++) {
	if (*s == '\0')
	    return 0;
    }

    return *s - *t;

}


