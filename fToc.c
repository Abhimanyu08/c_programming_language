#include <stdio.h>

double fToC(int f);

void main() {
    int fahr = 0;


    int start = 0;
    int upper = 300;

    printf("Fahrenheit\tCelsius\n");
    while (fahr < upper) {
	printf("%12d\t%10.2f\n", fahr, fToC(fahr));
	fahr += 20;
    }

}


double fToC(int f) {
    return (f - 32)*5.0/9.0;
}
