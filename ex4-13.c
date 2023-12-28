#include <stdio.h>



void reverse(char s[]) {
    
    int i;
    for (i = 0; s[i] != '\0'; i++)
	;

    char r[i];

    for (i = 0; s[i] != '\0'; i++) {
	if (i == 0) 
	    continue;

	r[i-1] = s[i];
    }
    r[i-1] = s[i];

    if (i == 0 || i == 1) 
	return;
    
    reverse(r);
    char first;
    first = s[0];
    for (i = 0; r[i] != '\0'; i++){
	s[i] = r[i];	
    }

    s[i++] = first;
    s[i] = '\0';

}

main() {

    char s[] = "hello";
    reverse(s);
    printf("hello reversed is %s\n", s);
}
