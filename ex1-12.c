#include <stdio.h>


#define IN 0
#define OUT 1



main() {

    int c;
    int lc, wc, cc;
    int STATE = OUT;



    while ((c = getchar()) != EOF) {

	if (c == ' ' || c == '\n' || c == '\t') {
	    putchar('\n');
	} else {
	    putchar(c);
	}

    }



}
