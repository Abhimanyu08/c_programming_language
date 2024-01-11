
#include "alloc.h"

#define BUFFSIZE 10000

static char allocbuffer[BUFFSIZE];
static char* allocp = allocbuffer;



char* allocn(int n) {
    
    if (allocbuffer + BUFFSIZE - allocp > n) {
	allocp += n;
	return allocp - n;
    }


    return 0; //no room for n chars
    
}

void allocfree(char* p) {
    
    if (allocbuffer + BUFFSIZE >p && p >= allocbuffer) 
	allocp = p;
    
}

