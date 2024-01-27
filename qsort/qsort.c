#include "string.h"
#include "getlines.h"


#define NUMLINES 1000

void swap(char* l[], int i, int j) {

    char* temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}


void qsort(char *lines[], int left, int right) {

    if (left >= right) 
	return;

    char* pivot = lines[right]; 

    int i,last;
    last = left;

    for (i = left; i < right; i++) {
	if (strcompare(lines[i], pivot) < 0) {
	    swap(lines,i, last++);
	}
    }

    swap(lines, last, right);

    qsort(lines, left, last-1);
    qsort(lines, last+1, right);

}


main() {
    
    char* lines[NUMLINES];
    
    int numlines;
    numlines= getlines(lines);

    qsort(lines, 0, numlines-1);
    writelines(lines, numlines);
}


