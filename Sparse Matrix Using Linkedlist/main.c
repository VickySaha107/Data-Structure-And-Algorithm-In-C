//
//  main.c
//  Sparse Matrix Using Linkedlist
//
//  Created by Bikramjit Saha on 04/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//


#include <stdio.h>

#include <stdlib.h>

struct Node{

int col;

int data;

struct Node *next;

}*first=NULL;

void Create(struct Node *A[],int m,struct Node *p)

{

int i,k;

struct Node *last=NULL;



for(i=0;i<m;i++)

{

printf("Enter nuber of element in row %d\n",i);

scanf("%d",&k);

A[i]=NULL;

for(int j=0;j<k;j++)

{



p=(struct Node *)malloc(sizeof(struct Node));

printf("Enter column and data");

scanf("%d%d",&p->col,&p->data);

p->next=NULL;

if(A[i]==NULL)

{

A[i]=p;

last=p;

}

else {

last->next=p;

last=p;

}

}

}

}

void Display(struct Node *A[],int m,int n)

{

struct Node *p=NULL;

int i,j;

for(i=0;i<m;i++)

{

p=A[i];

for(j=0;j<n;j++)

{

if(p && j==p->col)

{

printf("%d ",p->data);

p=p->next;

}

else

printf("0 ");

}

printf("\n");

}

}

int main()

{

struct Node *A[5];

Create(A,5,first);

Display(A,5,6);

return 0;

}

