#include <stdio.h>



unsigned setbits(unsigned, int, int, unsigned);


main(){ 
    unsigned x = 73;
    unsigned y = 180;

    unsigned z;

    z = setbits(x, 4, 3, y);

    printf("%hhu\n", z);
}





unsigned setbits(unsigned x, int p, int n, unsigned y) {


    char mask = ~(~0 << n);
    char yn = y & mask;

    mask = mask << (p-n+1);

    yn = yn << (p-n+1);

    char nmask = ~mask;
    char ymask;
    ymask = yn | nmask;

    return (x | mask) & ymask;


}
