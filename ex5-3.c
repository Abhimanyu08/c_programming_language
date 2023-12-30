#include <stdio.h>


void strcat(char* s,  char* t){

    for (;*s != '\0'; s++)
	;

    *s++ = ' ';
    while (*s++ = *t++) 
	;
}

main() {
    
    char s[20] = "hello";
    char t[] = "world";

    strcat(s,t);

    printf("s = %s\n", s);
    
}
