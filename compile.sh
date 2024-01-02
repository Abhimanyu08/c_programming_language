gcc -c alloc.c -o alloc.o
gcc -c strcpy.c -o strcpy.o
gcc -c ex5-7.c -o ex5-7.o
gcc alloc.o strcpy.o ex5-7.o -o ex5-7
./ex5-7

