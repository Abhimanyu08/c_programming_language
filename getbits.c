#include <stdio.h>


unsigned getbits(unsigned,  int, int);

main() {
    
    char x;
    x = 75;


    char y;
    y = getbits(x, 4, 3);
    printf("%d", y);
}

unsigned getbits(unsigned x,  int p, int n) {
    
    return (x >> (p+1-n)) & ~(~0 << n) ;
}
