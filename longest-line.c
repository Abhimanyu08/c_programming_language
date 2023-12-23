#include <stdio.h>


#define MAXIMUM 1000
int gline(char line[]);
void copy(char from[], char to[]);
void main() {
    
    char line[MAXIMUM];
    char longest[MAXIMUM];

    int len,max;
    max = 0;
 
    while ((len = gline(line)) > 0) {
	if (len > max) {
	    max = len;
	    copy(line, longest);
	}
    }
    printf("%s\n", longest);

}


int gline(char line[]) {
    int c,i;
    for (i = 0; i < MAXIMUM-1 && (c = getchar()) != EOF && c != '\n'; i++) {
	line[i]	 = c;
    }
    if (c == '\n') {
	line[i] = c;
	i++;
    }
    line[i] = '\0';

    return i;
}
void copy(char from[], char to[]) {
    
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0')
	i++;
}
