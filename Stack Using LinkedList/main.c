//
//  main.c
//  Stack Using LinkedList
//
//  Created by Bikramjit Saha on 06/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//
//


#include <stdio.h>

#include <stdlib.h>

struct Node

{

int data;

struct Node *next;

}*top=NULL;

void push(int x)

{

struct Node *t;

t=(struct Node*)malloc(sizeof(struct Node));

if(t==NULL)

printf("stack is full\n");

else

{

t->data=x;

t->next=top;

top=t;

}

}

int pop()

{

struct Node *t;

int x=-1;

if(top==NULL)

printf("Stack is Empty\n");

else

{

t=top; top=top->next;

x=t->data;

free(t);

}

return x;

}
int Peek(int Pos){
int i;
struct Node*t=top;
for (i=0; t!=NULL && i<Pos-1; i++) {
    t=t->next;
}
return t?t->data:-1;
}


int StackTop(){
    return top?top->data:-1;
}


int IsEmpty(){
    return top?0:1;
}


int isFull(){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    return t?0:1;
}


void Display()

{

struct Node *p;

p=top;

while(p!=NULL)

{

printf("%d ",p->data);

p=p->next;

}

printf("\n");

}

int main()
{

    
push(10);

push(20);

push(30);

    
Display();

printf("%d\n",pop());

return 0;

}
