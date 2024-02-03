#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h"


struct node {
    char* word;
    int count;
    struct node* left;
    struct node* right;
};


struct node* nodealloc(void) {
    return (struct node*)(malloc(sizeof(struct node)));
}

char* wordalloc(char* word) {
    
    char* p;

    p = (char*)(malloc(strlen(word)+1));
    if (p != NULL)
	strcpy(p, word);


    return p;
}

void treeadd(struct node* root, char* word) {
    
    struct node* current_node = root;
    char t[WORDLENGTH];

    
    int cmp;
    int flag = 0;
    struct node* new_node;
    while (current_node->word != NULL) {
	cmp = strcmp(word, current_node->word);

	if (cmp == 0) {
	    current_node->count++;
	    return;
	} else if (cmp < 0) {
	    if (current_node->left != NULL) {
		current_node = current_node->left;
	    }
	    else {
		flag = -1;
		break;
	    }
	} else {
	    if (current_node->right != NULL) {
		current_node = current_node->right;
	    }
	    else {

		flag = 1;
		break;
	    }
	}
    }
    
    
	new_node = nodealloc();
    	new_node->word = wordalloc(word);
	new_node->count = 1;
	new_node->left = new_node->right = NULL;
	if (flag == 0) {
		*current_node = *new_node; 
	} else if (flag == -1) {
		current_node->left = new_node;
	} else {
		current_node->right = new_node; 
	}


}

void treeprint(struct node* root) {
    
    if (root->left != NULL)
	treeprint(root->left);

    printf("word: %s, count: %d\n", root->word, root->count);

    if (root->right != NULL)
	treeprint(root->right);

}

main(){

    
    
    char word[WORDLENGTH];
    struct node root = {NULL, 0, NULL, NULL};

    int signal;
    while ((signal = getword(word)) != EOF) {
	
	//1. find word in a binary tree returning the struct corresponding to that word
	treeadd(&root, word);
	
    }

    treeprint(&root);
}
