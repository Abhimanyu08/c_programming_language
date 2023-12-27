#include <stdio.h>



unsigned setbits(unsigned, int, int, unsigned);


main(){ 
    unsigned x = 190;
    unsigned y = 90;

    unsigned z;

    z = setbits(x, 3, 2, y);

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
