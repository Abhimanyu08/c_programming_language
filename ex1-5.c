#include <stdio.h>


void main() {

    for (int fahr = 300; fahr >= 0; fahr -= 20) {
	printf("%5d\t%5.2f\n", fahr, (fahr-32)*5.0/9.0); 
    }

}
