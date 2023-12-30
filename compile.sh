gcc -c alloc.c -o alloc.o
gcc -c strcpy.c -o strcpy.o
gcc -c sortlines.c -o sortlines.o
gcc alloc.o strcpy.o sortlines.o -o sortlines
./sortlines

