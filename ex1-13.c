#include <stdio.h>

#define IN 0
#define OUT 1


main(){
    
    int count[10];     
    int STATE = IN;
    int i,c;
    int cw = 0;


    for (i = 0; i < 10; i++){
	count[i] = 0;
    }
    
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    STATE = OUT;
	    count[cw]++;
	    cw = 0;
	} else {
	    if (STATE == OUT) {
		STATE=IN;
	    }
	    cw++;
	}
    }
    count[cw]++;

    printf("\n");
    for (i = 1; i < 10; i++){

	printf("%d: %d\n", i, count[i]);
    }
    printf("\n");
    for (i = 1; i < 10; i++){
	printf("%d\t", i);
    }
    printf("\n");
    int max = 0;
    for (i =1; i< 10; i++) {
	if (count[i] > max) 
	    max = count[i];
    }
    int j;
    for (i = 1; i <= max; i++) {
	for (j=1; j < 10;j++) {
	    if (count[j] >= i) {
		printf("#\t");
		continue;
	    }
	    printf(" \t");
	}
	printf("\n");
    }

    printf("\n");
 
}
