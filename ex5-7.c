#include <stdio.h>
#include "alloc.h"
#include "strcpy.h"
#define MAXLEN 1000
#define MAXLINES 5000
#define COMBINED_LENGTH 1000

int getl(char*, int);
int getlines(char* lineptrs[], char [], int);
void writelines(char* lineptrs[], int);
void qsort(char* lineptrs[], int, int);
void swap(char* lineptrs[], int, int);

main(){
    
    char* lineptrs[MAXLINES];
    char alllines[COMBINED_LENGTH];
    
    int i,numlines;
    numlines = getlines(lineptrs, alllines, MAXLINES);
    qsort(lineptrs, 0, numlines-1);

    writelines(lineptrs, numlines);
}

int getlines(char* lineptrs[], char alllines[], int maxlines) {
    

    char line[MAXLEN];
    int len;
    int start = 0;
    int i = 0;
    while ((len = getl(line, MAXLEN)) > 0) {
	
	if (i >= maxlines) 
	    return -1;

	stringcopy(line, &alllines[start]);
	lineptrs[i++] = &alllines[start]; 
	start += len;
    }
    return i;

}

int getl(char* s, int max) {
    
    int c,i;
    
    for (i=0; (c = getchar()) != EOF && c != '\n' && i < max; i++) {

	*s++ = c;
    }


    if (i >= max)
	return -1;
    if (i == 0)
	return i;

    *s = '\0';
    return i+1;

}

void writelines(char* lineptrs[], int numlines) {
    int i;
     for (i =0; i < numlines; i++) 
	printf("%s\n", lineptrs[i]);


}
void qsort(char* lineptrs[], int left, int right) {
    
    if (left >= right)
	return;

    char* pivot = lineptrs[right];
    int lastindex = left;
    int i;

    for (i = left; i <= right-1; i++) 
	if (stringcmp(lineptrs[i], pivot) < 0)
	    swap(lineptrs, i, lastindex++);
    
    
    swap(lineptrs, lastindex, right);

    qsort(lineptrs, left, lastindex-1);
    qsort(lineptrs, lastindex+1, right);
}

void swap(char* lineptrs[], int i, int j) {
    
    char* temp;
    temp = lineptrs[i];
    lineptrs[i] = lineptrs[j];
    lineptrs[j] = temp;
}

