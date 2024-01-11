#include <stdio.h>
#include "string.h"
#include "alloc.h"
#include "getlines.h"


#define MAXLENGTH 1000
#define NUMLINES 10
int getl(char* s) {
    

    int i,c;
    for (i = 0; (c = getchar()) != '\n' && c != EOF; i++)
	*s++ = c;	

    if (i == 0)
	return 0;

    *s = '\0';


    return i+1;
}

int getlines(char* lines[]) {

    char s[MAXLENGTH];
    char* p;

    int len,i;
    for (i = 0;(len = getl(s)) > 0 && (p = allocn(len)) != NULL; i++) {
	
	strcopy(s, p);
	lines[i] = p;
    }

    return i;
}

void writelines(char* lines[], int numlines) {
    
    int i;
    for (i = 0; i < numlines; i++)
	printf("%s\n", lines[i]);
}


