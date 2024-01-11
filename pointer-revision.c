#include <stdio.h>



int strlen(char* s) {
    int i;

    for (i = 0; *s++ != '\0'; i++)
	;

    return i;
}


void strcpy(char* s, char* t) {
    
    while (*t++ = *s++)
	;
}

int strcmp(char *s, char* t) {
    
    for (;*s == *t; s++, t++) {
	if (*s == '\0')
	    return 0;

    }

    return *s - *t;
}

main() {
    

    char s[] = "hello";
    char t[] = "hella";


    printf("comparison: %d\n", strcmp(s,t));

}

