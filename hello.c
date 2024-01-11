#include <stdio.h>


void main() {
    int a[3] = {1,2,3};

    int second_element = a[10];
    int first_element = *a;


    printf("First: %d, second: %d\n", first_element,second_element);
    printf("a: %p\n", a);
}



