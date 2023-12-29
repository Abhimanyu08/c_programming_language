#include <stdio.h>


void f(int* a) {
    int i;
    for (i = -6; *(a+i) != 18; i++) 
	printf("%d\n", *(a+i));
}

main() {
    int a[10];

    for (int i = 0; i < 10; i++)
	a[i] = i*2;


    f(&a[4]);
}


