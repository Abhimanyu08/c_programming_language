#include <stdio.h>
#include "getl.h"
#include "search.h"

#define MAXLEN 1000

main(int argc, char* argv[]) {
    //example arguments find -n -x pattern
    if (argc < 2) {
	printf("Usage: find -n -x pattern\n");
    }

    int sln = 0, exclude= 0;

    int i;
    char* arg;
    char option;

    for (i = 1; i < argc -1 ; i++) {
	
	arg = argv[i];
	if (*arg != '-')
	    break;

	while (*++arg != '\0') {
	    option = *arg;
	    switch (option) {
		case 'x':
		    exclude = 1;
		    break;
		case 'n':
		    sln = 1;
		    break;

		default:
		    printf("find: Illegal option %c", option);
		    argc = 0;
		    break;
    
	    } 
	}
    }
    
    char* pattern;

    pattern = argv[i];

    int len;
    char line[MAXLEN];
    int lineno = 0;
    while ((len = getl(line)) > 0) {
	lineno++;
	if (search(line, pattern) != exclude) {
	    if (sln)
		printf("%d: ", lineno);
	    printf("%s\n", line);
	}
    } 

}

