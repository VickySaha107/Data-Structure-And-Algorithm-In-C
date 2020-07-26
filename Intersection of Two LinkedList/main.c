//
//  main.c
//  Intersection of Two LinkedList
//
//  Created by Bikramjit Saha on 06/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
}*first = NULL;
 
struct Node* second = NULL;
 
void create(int a[] , int n)
{
    int i;
    struct Node *t , *last;
    first = (struct Node *)malloc(sizeof(struct Node));
 
    first->data = a[0];
    first->next = 0;
    last = first;
 
    for(i=1 ; i<n ; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
 
}
 
void createSecond(int b[] , int n , struct Node *p)
{
    int i;
    struct Node *t , *last;
    second = (struct Node *)malloc(sizeof(struct Node));
 
    second->data = b[0];
    second->next = 0;
    last = second;
 
    for(i=1 ; i<n ; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = b[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
 
    last->next = p;
 
}
 
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d " , p->data);
        p = p->next;
    }
}
 
 
struct stack
{
    int size;
    int top;
    struct Node **S;
};
 
void createStack(struct stack *st , int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node *));
 
}
 
void push(struct stack *st , struct Node *val)
{
    if(st->top == st->size -1)
    {
        printf("stack overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = val;
    }
}
 
struct Node *pop(struct stack *st)
{
    struct Node *x = NULL ;
 
    if(st->top == -1)
    {
        printf("stack empty\n");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
 
    return x;
}
 
int isEmpty(struct stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
struct Node *stackTop(struct stack st)
{
    if(!isEmpty(st))
    {
        return st.S[st.top];
    }
 
    return NULL;
}
 
 
 
int Intersection(struct Node *p, struct Node *q)
{
    struct stack st1, st2;
    struct Node *result = NULL;
 
    createStack(&st1 , 100);
    createStack(&st2 , 100);
 
    while(p)
    {
        push(&st1, p);
        p = p->next;
    }
 
    while(q)
    {
        push(&st2, q);
        q = q->next;
    }
 
 
    while(stackTop(st1) == stackTop(st2))
    {
        result = stackTop(st1);
        pop(&st1);
        pop(&st2);
    }
 
    return result->data;
}
 
 
 
int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, 11);
 
 
    struct Node* temp = first;
    int i = 5;
 
    while (i>0)
    {
        temp = temp->next;
        i--;
    }
 
    int B[] = {2, 4, 6, 8, 10};
    createSecond(B, 5, temp);
 
    display(first);
 
    printf("\n");
 
    display(second);
 
    printf("\n");
 
    printf("%d\n",Intersection(first,second));

    return 0;
}
