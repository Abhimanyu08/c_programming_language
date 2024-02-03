gcc -c getword.c -o getword.o
gcc -c main.c -o main.o
gcc getword.o main.o -o main

