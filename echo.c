#include <stdio.h>


main(int argc, char* argv[]){

    
    int i;
    printf("argc: %d\n", argc);
    for (i = 1; i < argc; i++) 
	printf("%s%s", *++argv, (i < argc -1) ? " ": "");
    
    printf("\n");

}
