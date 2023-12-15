#include <stdio.h>



main() {

    int c, nwhite, nother;
    int i;
    int ndigit[10];


    nwhite = nother = 0;
    for (i = 0; i < 10; i++){
	ndigit[i] = 0;
    }


    while ((c = getchar()) != EOF) {

	if (c >= '0' && c <= '9') {
	    ndigit[c - '0']++;
	}
	else if (c == '\n' || c == ' ' || c == '\t') 
	    nwhite++;
	
	else
	    nother++;
	
    }


    for (i = 0; i < 10; i++){
	printf("No of %ds: %d \n",i, ndigit[i]);
    }
    printf("No of white chars: %d\n",nwhite);
    printf("No of chars: %d\n",nother);
}
