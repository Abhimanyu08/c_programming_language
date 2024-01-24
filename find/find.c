#include <stdio.h>
#include "getl.h"

#define MAXLEN 1000







main() {

    int len;
    char pattern[] = "ould";
    char s[MAXLEN];

    while ((len = getl(s)) > 0)
	if (search(s, pattern) > 0)
	    printf("%s\n", s);

    printf("\n");

}
