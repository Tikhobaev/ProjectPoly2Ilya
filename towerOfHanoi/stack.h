#ifndef stack_h
#define stack_h
#include <stdio.h>

struct node
{
	int value;
	node* pnext;
};

node* push(node*, int);

node* pop(node*);

int isEmpty(node *);

int compare(node*, node*);

void print(node*);

int count(node*);

#endif