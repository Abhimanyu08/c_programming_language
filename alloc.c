#include "alloc.h"
#define SIZE 1000
static char allocbuffer[SIZE];

static char* allocp = allocbuffer;


char* alloc(int n) {
    
    if (allocbuffer + SIZE - allocp > n) {
	allocp += n;
	return allocp - n;
    }
    return 0;
}

void afree(char* p) {
    
    if (p >= allocbuffer && p < allocbuffer + SIZE) 
	allocp = p;
	
}



