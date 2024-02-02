gcc -c keytab.c -o keytab.o
gcc -c strcmp.c -o strcmp.o
gcc -c getword.c -o getword.o
gcc -c main.c -o main.o
gcc keytab.o strcmp.o getword.o main.o -o main

