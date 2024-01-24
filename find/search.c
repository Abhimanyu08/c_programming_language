#include "search.h"
int search(char line[], char pattern[]){
    
    char* p = pattern;

    int i = 0,j;
    while (line[i] != *p && line[i] != '\0')
	i++;

    if (line[i] == '\0')
	return 0;

    char* l;
    l = &line[i];

    for (;*l == *p; l++, p++)
	if (*l == '\0')
	    return 1;
    
    if (*p == '\0')
	return 1;

    if (*l == '\0')
	return 0;

    return search(&line[i+1], pattern);
    
}
