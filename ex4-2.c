#include <ctype.h>
#include <stdio.h>


main() {
    
    double atof(char s[]);
    printf("%f\n", atof("123.456e-3"));

}


double atof(char s[]) {


    //s = -123.45e-6

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
    double exponent = 1;
    if (s[i] == 'e')  {

	int exp_sign,mantissa; 

	exp_sign= (s[++i] == '-') ? -1: 1;
	mantissa = s[++i] - '0';

	for (int j = 0; j < mantissa; j++) {
	    exponent *= 10.0;
	} 
	printf("exponent before: %f\n", exponent);
	if (exp_sign < 0) {
	    exponent = 1.0/exponent;
	}
	printf("exponent after: %f\n", exponent);

    }
    return sign* (val/power)*exponent;

}
