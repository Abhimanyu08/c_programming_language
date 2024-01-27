#include "string.h"
#include "getlines.h"


#define NUMLINES 1000

void swap(void* l[], int i, int j) {

    void* temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}


void qsort(void *lines[], int left, int right, int(*cmp)(void*, void*)) {

    if (left >= right) 
	return;

    char* pivot = lines[right]; 

    int i,last;
    last = left;

    for (i = left; i < right; i++) {
	if (cmp(lines[i], pivot) < 0) {
	    swap(lines,i, last++);
	}
    }

    swap(lines, last, right);

    qsort(lines, left, last-1,cmp);
    qsort(lines, last+1, right,cmp);

}


main(int argc, char* argv[]) {
    
    char* lines[NUMLINES];
    
    int numlines;
    numlines= getlines(lines);

    int num = 0;
    if (argc > 1) {

	char* option = argv[1];
	if (option[0] == '-' && option[1] == 'n') {
	    num = 1;
	}
    }
    qsort((void**)lines, 0, numlines-1, (int(*)(void*,void*))(num ? numcompare: strcompare));
    writelines(lines, numlines);
}


