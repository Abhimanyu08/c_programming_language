#include <stdio.h>
#include "keytab.h"
#include "stringcompare.h"
#include "getword.h"

#define WORDLENGTH 100 


struct key* binsearch(char* word, int start, int end) {

    if (start >= end) 
	return NULL;
    struct key* middle;
    int middle_index =(start+end)/2;

    middle = &keytab[middle_index];

    int cmp = stringcompare(word, middle->word);
    if (cmp == 0) {
	return &keytab[middle_index];
    }
    if (cmp < 0) {
	return binsearch(word, 0, middle_index-1);
    } else {
	return binsearch(word, middle_index+1, end);
    }
}

main() {
    
    char* word;


    //1. get a word from STDIN
    //2. bin search that word in keytab
    //3. increase the count field of that structure
    
    int signal;
    struct key* keystat;

    while ((signal = getword(word)) != EOF) {

	if ((keystat = binsearch(word, 0, NKEYS)) != NULL) {
	    keystat->count++;
	}

    }
    int i;
    
    for (i = 0; i < NKEYS; i++) {
	printf("key: %s, count: %d\n", keytab[i].word, keytab[i].count);
    }
    
}




