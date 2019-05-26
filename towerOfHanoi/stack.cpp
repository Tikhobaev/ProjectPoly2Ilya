#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include <stdlib.h>

node* push(node* phead, int val)
{
	node *p = (node*)malloc(sizeof(node));
	p->value = val;
	p->pnext = phead;
	return p;
}

node* pop(node* phead)
{
	node *p = phead->pnext;
	free(phead);
	return p;
}

int isEmpty(node *phead)
{
	if (phead)
		return 0;
	return 1;
}

int compare(node* p, node* p2)
{
	for (int i = 0; i < 3; i++)
	{
		if(isEmpty(p)||isEmpty(p2))
		{
			return 0;
		}
		if (p->value == p2->value)
		{
			p = p->pnext;
			p2 = p2->pnext;
		}
		else return 0;
	}
	return 1;
}

void print(node* phead)
{
	node* p = phead;
	while (!isEmpty(p))
	{
		printf("%d ", p->value);
		p = p->pnext;
	}
	printf("\n");
}

int count(node* phead)
{
	int count = 0;
	node* p = phead;
	while (!isEmpty(p))
	{
		count ++;
		p = p->pnext;
	}
	return count;
}