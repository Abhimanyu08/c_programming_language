#include <stdio.h>



main() {

    int c;


     c = getchar();
    while (c != EOF) {
	putchar(c + 'A' - 'a');
	c = getchar();
    } 

}


