#include <stdio.h>

int main() {
    int x = 42;
    int *ptr = &x;

    // Print the value of the pointer
    printf("Value of the pointer: %p\n", (void *)ptr);

    return 0;
}

