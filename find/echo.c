#include <stdio.h>



main(int argc, char* argv[]) {


    int i;
    for (i = 1; i <argc; i++)
	printf((i == argc -1) ? "%s": "%s ", *(argv + i));
    printf("\n");

}
