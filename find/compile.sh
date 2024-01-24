gcc -c getl.c -o getl.o
gcc -c find.c -o find.o
gcc find.o getl.o -o find
./find

