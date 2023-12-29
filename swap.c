#include <stdio.h>


void swap(int* x, int* y) {
    int temp;
    temp   = *x;
    *x = *y;
    *y = temp;
}

main() {
    int x = 20;
    int y = 10;


    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
}
