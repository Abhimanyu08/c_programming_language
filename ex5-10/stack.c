#include <stdio.h>
#include "stack.h"

#define STACKSIZE 100


static double stack[STACKSIZE];
static int stacktop = 0;


void push(double ch) {
    if (stacktop < STACKSIZE) {
	stack[stacktop++] = ch;
    }
}


double pop() {
    
    if (stacktop > 0) {
	return stack[--stacktop];
    }

    return 0; 
}



