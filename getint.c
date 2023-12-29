#include <stdio.h>
#include <ctype.h>


#define SIZE 20

int getint(int* p) {
    
    static int extra = 0;
    int c;

    if (extra != 0) {
	c = extra;
	extra = 0;
    } 
    else 
	c = getchar();
	
    while (isspace(c)) 
	c = getchar();

    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
	extra = c;
	return 0;
    }

    int sign;
    sign = (c == '-') ? -1: 1;

    if (c == '+' || c == '-') 
	c = getchar();


    for (*p = 0; isdigit(c); c = getchar()) 
	*p = 10* *p + (c - '0');
    
    *p *= sign;

    if (c != EOF) {
	extra = c;

    }
    return c;
    
}

main(){
    
    int i, array[SIZE];


    for (i = 0; i <  SIZE && getint(&array[i]) != EOF;i++)
	;

    printf("\n---------Array: --------\n");
    for (int j = 0; j <= i; j++){
	printf("%d\n", array[j]);
    }

}



