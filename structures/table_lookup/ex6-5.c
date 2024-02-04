// we are essentially making a hashtable here.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 2


struct list_item {
    
    struct list_item* next;
    char* name;
    char* value;
};

struct list_item* hashtable[TABLE_SIZE];

struct list_item* itemalloc();
char* wordalloc(char* word);
unsigned hash(char* name); 



struct list_item* lookup(char* name) {
    
    unsigned index = hash(name);

    struct list_item* p;

    for (p = hashtable[index]; p != NULL; p = p->next) {
	if (strcmp(p->name, name) == 0)
	    return p;
    } 

    return NULL;
}





void install(char* name, char* value) {
    

    struct list_item* p;
    p = lookup(name);

    unsigned index;
    struct list_item* new_item;
    if (p == NULL) {
	index = hash(name);
	new_item = itemalloc();

	new_item->name = wordalloc(name);
	new_item->value = wordalloc(value);
	//put this new_item at the start of the linked list.
	new_item->next = hashtable[index]; 

	hashtable[index] = new_item;
	return;
    }


    free((void *)(p->value));
    p->value = wordalloc(value);

    return;
}

void undef(char* name) {
    
    unsigned hashindex;

    hashindex = hash(name);

    struct list_item* current_item;

    current_item = hashtable[hashindex];

    struct list_item* previous = NULL;

    while (current_item != NULL) {
	
	if (strcmp(current_item->name, name) == 0) {
	    if (previous == NULL) 
		hashtable[hashindex] = current_item->next;
	    else 
		previous->next = current_item->next;
	    free((void*)(current_item->name));
	    free((void*)(current_item->value));
	    free((void*)(current_item));
	    break;
	}
	
	previous = current_item;
	current_item = current_item->next;

    }

}

void loghashtable() {
    
    int i;
    struct list_item* p;
    for (i = 0; i < TABLE_SIZE; i++) {
	
	p = hashtable[i];
	while (p != NULL) {
	    printf("index: %d, key: %s, val: %s\n", i, p->name, 
	    lookup(p->name)->value);
	    p = p->next;

	}
    }

}

main() {
    
    install("a", "1");   
    install("b", "2");   
    install("c", "3");   
    install("d", "4");   
    install("e", "5");   
    install("f", "6");   
    install("g", "7");   

    undef("b");
    undef("e");

    loghashtable();

}

struct list_item* itemalloc() {
    return (struct list_item*)malloc(sizeof(struct list_item));
}

unsigned hash(char* name) {

    unsigned hashval;

    for (hashval = 0;*name != '\0'; name++) 
	hashval = *name + hashval*31;

    return hashval%TABLE_SIZE;
}

char* wordalloc(char* word) {
    
    char* p;

    p = (char*)(malloc(strlen(word)+1));
    if (p != NULL)
	strcpy(p, word);


    return p;
}
