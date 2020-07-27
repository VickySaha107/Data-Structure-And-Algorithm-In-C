//
//  main.c
//  Queues Using 2 Stacks
//
//  Created by Bikramjit Saha on 18/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct Node {
int data;
struct Node *next;
}*top=NULL;
void push(struct Node *st,int x)
{
struct Node *t;
t = (struct Node *)malloc(sizeof(struct Node));
if(t == NULL)
{
printf("stack full\n");
}
else
{
t->data = x;
t->next = top;
top = t;
}
}
int pop(struct Node *st)
{
struct Node *p;
int x= -1;
if(top == NULL)
{
printf("stack is empty\n");
}
else
{
p = top;
top = top->next;
x = p->data;
free(p);
}
return x;
}
int isEmpty(struct Node st)
{
if(top == NULL)
{
return 1;
}
return 0;
}
void enqueue(struct Node *s2,int data)
{
push(s2,data);
}
int dequeue(struct Node *st1,struct Node *st2)
{
int x = -1;
if(isEmpty(*st2))
{
if(isEmpty(*st1))
{
printf("Queue is Empty\n");
return x;
}
else{
while(!isEmpty(*st2))
{
push(st2,pop(st1));
}
}
}
return pop(st2);
}
void display()
{
struct Node *p = top;
while(p!=NULL)
{
printf("%d " , p->data);
p = p->next;
}
printf("\n");
}
int main(){
    struct Node *st1 = NULL,*st2=NULL;
    push(st1, 10);
    push(st1, 20);
    push(st2, 40);
    push(st2, 70);
    push(st1, 50);
    display();
    printf("%d\n",pop(st1));
    display();
    return 0;
}
