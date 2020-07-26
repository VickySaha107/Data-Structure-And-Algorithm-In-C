//
//  main.c
//  Dequeue Using LinkedList
//
//  Created by Bikramjit Saha on 18/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*front,*rear=NULL;
 
 
 
void insertFront(int val)
{
    struct Node *t;
 
    t = (struct Node *)malloc(sizeof(struct Node));
 
     if(t==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data = val;
        t->next = NULL;
 
        if(front==NULL)
        {
            front = rear = t;
        }
        else
        {
            t->next = front;
            front = t;
        }
    }
}
 
void insertRear(int val)
{
    struct Node *t;
 
    t = (struct Node *)malloc(sizeof(struct Node));
 
    if(t==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data = val;
        t->next = NULL;
 
        if(front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
 
int DeleteFront()
{
    int x = -1;
    struct Node *p;
 
    if(front == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
 
    return x;
}
 
int DeleteRear(){

    int x = -1;
    struct Node *p;
    if(front == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        p = front;
        // Traverse Pointer p until it reaches rear
        while(p->next!= rear)    // T.C-O(n)
        {
            p = p->next;
        }
        x = rear->data;
        free(rear);
        rear = p;
        rear->next = NULL;
    }
 
    return x;
}
 
void display(struct Node *p)
{
   
 
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
 
 
int main(int argc, const char * argv[]) {
// insert code here...
    
    insertRear(10);
    insertRear(20);
    insertRear(30);
    insertRear(40);
 
    display(front);
 
    printf("Deleted front's Data: %d\n" , DeleteFront());

    display(front);
 
    insertFront(80);
    insertFront(70);
    insertFront(60);
 
    printf("\n");
    display(front);
 
    printf("Deleted rear's Data: %d\n" , DeleteRear());
    printf("\n");
    display(front);
 
 
    return 0;
}

