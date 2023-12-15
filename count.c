//this program counts lines, words and characters


#include <stdio.h>


#define IN 0
#define OUT 1


main() {

    int c;
    int lc, wc, cc;
    int STATE = OUT;

    lc = wc = cc = 0;


    while ((c = getchar()) != EOF) {

	if (c == '\n')  {
	    lc++;
	}


	if (c == ' ' || c == '\n' || c == '\t') {
	    STATE=OUT;
	} else {
	    if (STATE==OUT) {
		wc++;
	    }
	    STATE = IN;
	    cc++;
	}

    }

    printf("\nNo of lines: %d\nNo of words: %d\nNo of characters:%d\n"
    ,lc,wc,cc
    );

}
