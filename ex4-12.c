#include <stdio.h>


#define MAXCHAR 10


void itoa(int num, char s[]) {
    
    if (num / 10) {
	itoa(num/10, s);
	int i;

	for (i = 0; s[i] != '\0'; i++)
	    ;

	s[i++] = num % 10 + '0';
	s[i] = '\0';
    }

    else {
	s[0] = num + '0';
	s[1] = '\0';
    }

}

main() {
    
    char s[MAXCHAR];
    int inp = 231;
    itoa(231, s);
    printf("%s\n", s);
}
