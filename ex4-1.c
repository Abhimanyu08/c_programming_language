#include <stdio.h>



int strrindex(char s[],char t[]);


main() {
	
    char string[] = "this is the string to test things, could would should";
    char pattern[] = "ould";

    printf("%d\n", strrindex(string, pattern));
    
}

int strrindex(char s[],char t[]){
    
    int i,j,p;

    p = -1;
    for (i = 0; s[i] != '\0'; i++) {
	if (s[i] == t[0]) {
	    p =i;
	    j = 0;
	    while (s[i+j] == t[j] && t[j] != '\0') 
		j++;

	    if (j == 0 || t[j] != '\0') {
		p = -1;
	    }
	}	
    }

    return p;

}
