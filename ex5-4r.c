#include <stdio.h>



int strend(char* s, char* t){
    char* ps;
    char* pt;

    pt = t;
    for (;*s != *t && *s != '\0'; s++)
	;
    if (*s == '\0')
	return 0;

    ps = s;
    for (;*s == *t; s++,t++)
	if (*s == '\0')
	    return 1;
   
    return strend(++ps, pt);
}
main() {
    char s[] = "hello";
    char t[] = "lo";
    char u[] = "ello";
    char v[] = "ell";
    printf("%d\n", strend(&s[0], v));
}
