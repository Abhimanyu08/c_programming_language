#include <stdio.h>
#include <ctype.h>
#include "getword.h"

#define WORDLENGTH 100


int getword(char* word) {
    
    int c;
    char* w = word;

    while ((c = getchar()) != EOF && (isspace(c) || c == '\n' ))
	;

    if (!isalpha(c)) {
	//if c is EOF or c == ! for example
	*w = '\0';
	return EOF;
    }

    while (isalnum(c)) {
	
	*w++ = c;
	c = getchar();
    }

    *w = '\0';

    return word[0];
    
}



