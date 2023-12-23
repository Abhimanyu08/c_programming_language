#include <stdio.h>

#define chars "abcdefghijklmnopqrstuvwxyz"

void main() {
    
    int charcount[26];

    for (int i= 0; i <26; i++) {
	charcount[i] = 0;
    }
    

    int c,i;

    while ((c = getchar()) != EOF) {
	
	for (i =0; i <26; i++) {
	    if (chars[i] == c) {
		charcount[i]++;
	    }
	}
    }


    int maxcount = 0;

    for (i =0; i <26; i++) {
	if (charcount[i] > maxcount) maxcount = charcount[i];
    }

    printf("\n");
    for (i =0; i <26; i++) {
	printf("%c ", chars[i]);
    }

    printf("\n");
    for (int j = 1; j <= maxcount; j++) {
	for (i =0; i <26; i++) {
	    if (charcount[i] >= j) {
		printf("# ");
		continue;
	    }
	    printf("  ");
	}
	printf("\n");
    }

}
