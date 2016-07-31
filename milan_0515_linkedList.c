/* Program: Linked List.
Author: Milan Budhathoki.
Date: Sunday, July 31, 2016.
Reference: Data structures using C and C++, Chapter 4, page 188.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr *,int);
int deletefromfirst(nodeptr *);
void displaylist(nodeptr);

int main()
{
	nodeptr list;
	list=NULL;
	insertatfirst(&list,5);
	insertatfirst(&list,6);
	insertatfirst(&list,7);
	insertatfirst(&list,8);
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	printf("The deleted item is %d\n",deletefromfirst(&list));
	displaylist(list);
}

nodeptr getnode()
{
return (nodeptr) malloc(sizeof(struct node));	
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr *p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	while(p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->next;
	}
}

int deletefromfirst(nodeptr *p)
{
int x;	
nodeptr q;
q=*p;
if(q==NULL)
{
	printf("\nUNDERFLOW!!\n");
	exit(1);
}
else
{
x=q->info;
*p=q->next;
free(q);
return (x);
}
}
