#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"


main(int argc, char* argv[]) {
    

    int i;
    char* ch;
    double op2;
    for (i =1; i < argc; i++) {
	
	ch = argv[i];
	printf("arg: %s\n", ch);
	switch (*ch) {

	    case '+':
		push(pop() + pop());
		break;

	    case '-': 
		op2 = pop();
		push(pop() - op2);
		break;


	    default:
		push(atof(ch));
		break;
		
	}

    }


    printf("Result: %.2f\n", pop());

}








