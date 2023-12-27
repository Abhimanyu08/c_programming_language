#include <ctype.h>
#include <stdio.h>


main() {
    
    double atof(char s[]);
    printf("%f\n", atof("-314.2596"));

}


double atof(char s[]) {


    //s = -314.2596

    int i,sign;

    for (i=0; isspace(s[i]); i++) 
	;

    sign = (s[i] == '-') ? -1: 1;

    if (s[i] == '+' || s[i] == '-')
	i++;

    int val = 0;
    for (val = 0; isdigit(s[i]); i++) {
	val = 10*val + (s[i] - '0');
    }
    if (s[i] == '.')
	i++;

    double power;
    for (power = 1.0; isdigit(s[i]); i++) {
	val = 10*val + (s[i] - '0');
	power *= 10.0;
    }

    return sign* (val/power);

}
