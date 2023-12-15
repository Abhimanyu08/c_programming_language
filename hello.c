#include <stdio.h>

double fToC(int f);

void main() {
    int fahr = 0;


    int start = 0;
    int upper = 300;


    while (fahr < upper) {
	printf("%.2d\t%.2f\n", fahr, fToC(fahr));
	fahr += 20;
    }

}


double fToC(int f) {
    return (f - 32)*5.0/9.0;
}
