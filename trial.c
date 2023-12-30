#include <stdio.h>
#include "strcpy.h"



void swap(int list[], int i,int j){
    int temp;
    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void printlist(int list[],int left, int right) {
    int i;
    for (i = left; i <= right; i++)
	printf("%d ", list[i]);
    printf("\n");
}
void qsort(int list[], int left, int right) {
    
    if (left >= right) 
	return;
    
    int lastindex= left;
    int pivot = list[right];


    
    int i;
    for (i = left; i <= right -1; i++) {
	if (list[i] < pivot)  {

	    swap(list, i, lastindex++);
	 }
    }

    swap(list,lastindex, right);

    qsort(list, left, lastindex-1);
    qsort(list, lastindex+1, right);

}


main() {

    int list[] = {3,1,2,5,7,8,9,4,0,6};

    qsort(list, 0, 9);
    int i;
    for (i = 0; i < 10; i++)
	printf("%d ", list[i]);

    printf("\n");
}



