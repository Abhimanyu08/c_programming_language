#include <stdio.h>



int strend(char* s, char* t) {
    
    char* u;
    u = t;
    for (;*s != *t; s++) 
	;

    while (*s == *t && *s != '\0') {
	s++;
	t++;
    } 

    if (*s == '\0' && *t == '\0')
	return 1;
    if (*s == '\0' && *t != '\0')
	return 0;

    return strend(s, u);


}

main() {
    
    char s[] = "this is the test string to test";
    char t[] = "test";

    int res = strend(s, t);

    printf("res: %d\n", res); 

}
