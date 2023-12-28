//this program takes an input of the form  1 2 - 4 5 + * and calculates (1+2)*(4-5)
//

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


#define NUMBER '0'
#define MAXSIZE 100
int getop(char s[]); 
double stack[MAXSIZE];
int sp = 0; //current top of stack also equal to number of things on tstack


void push(double op) {
    if (sp < MAXSIZE) {
	stack[sp++] = op;
    }    
    else {
	printf("stack full\n");
    }
};
double pop(void) {
    if (sp > 0) {
	return stack[--sp];
    } else {
	printf("stack empty\n");
    }
}

main() {
    
    int type;
    char s[MAXSIZE];
    double op2;
    while ((type = getop(s)) != EOF) {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() * pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if (op2 == 0.0) {
		    printf("error: division by zero\n");
		} else 
		    push(pop() / op2);
		break;
	    case '\n':
		printf("\t%g\n", pop());
		break;
	    default:
		printf("unknown command, %s\n", s);
		break;
	}
    }
    return 0;
    
}


int getop(char s[]) {
    //this function writes operand or operator into s. this function needs to handle the input like 1234*+ gracefully. we can't tell we have reached the end of number until we have read till *

    //there can be tons of consecutive spaces the start of. we need to ignore those
    
    int i,c;
    static int extra = 0; 
    if (extra != 0) {
	c = extra;
	extra = 0;
    } else 
	c = getchar();
    while ((s[0] = c) == ' ' ||  c == '\t')
	c = getchar();
    

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
	return c; /*not a number*/


    i = 0;
    if (isdigit(c)) {
	while (isdigit(s[i++] = c)) 

	    c = getchar();

    }

    if (c == '.')
	while (isdigit(s[++i] = c))
	    c = getchar();

    s[i] = '\0';
    if (c != EOF) 
	extra = c;

    return NUMBER;

}



int getch(int extra) {
    int ch;

    ch = (extra != 0) ? extra: getchar();
    return ch;
}


