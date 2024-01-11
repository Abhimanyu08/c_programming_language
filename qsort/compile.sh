gcc -c alloc.c -o alloc.o
gcc -c string.c -o string.o
gcc -c getlines.c -o getlines.o
gcc -c qsort.c -o qsort.o
gcc alloc.o string.o getlines.o qsort.o -o qsort 
./qsort

