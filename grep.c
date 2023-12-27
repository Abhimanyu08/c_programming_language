#include <stdio.h>


#define MAXLEN 1000

char pattern[] = "ould";
int getl(char line[]);
int search_pattern(char line[] );

int main() {

    char line[MAXLEN];
    

    while (getl(line) > 0) {
	if (search_pattern(line) >= 0)
	    printf("%s", line);

    }
    return 0;

}

int getl(char line[]) {
    
    int i,c;
   for (i=0; (c = getchar()) != EOF && c != '\n' && i <MAXLEN-1; i++) {
	line[i] = c;
    }
    
    if (c == '\n') {
	line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

int search_pattern(char line[]) {

    
    int i, j;
    for (i =0; i < MAXLEN && line[i] != '\0'; i++) {

	if (line[i] == pattern[0]) {
	    j = 0;
	    while (pattern[j] != '\0') {
		if (pattern[j] == line[i+j]) 
		    j++;
		else break;
	    }
	    if (j > 0 && pattern[j] == '\0') {
		return j;
	    }

	}
    }
    return -1;
    
}


