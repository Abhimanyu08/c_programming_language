gcc -c getl.c -o getl.o
gcc -c find.c -o find.o
gcc -c search.c -o search.o
gcc find.o getl.o search.o -o find

