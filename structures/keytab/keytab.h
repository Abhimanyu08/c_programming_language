#ifndef KEYTAB_H
#define KEYTAB_H


#define NKEYS 32
struct key {
    char *word;
    int count;
};

extern struct key keytab[NKEYS];


#endif // !KEYTAB_H

