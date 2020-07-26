//
//  main.c
//  Inserting In A LinkList
//
//  Created by Bikramjit Saha on 16/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data ;
    struct Node *next;
}*first=NULL;/*first-GLOBAL POINTER */
void create(int A[],int n)
{
    int i;
struct Node *t,*last;/* *t-temp node */
  first=(struct Node *)malloc(sizeof(struct Node));
  first->data=A[0];
    first->next=NULL;
  last=first;
    for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
    t->next=NULL;
    last->next=t;
last=t;
}
}
void display(struct Node*p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void insert_Pos(struct Node*p,int pos,int val){
    struct Node*t;
    int i;
    if(pos<0) return;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=val;
        if (pos==0){
        t->next=first;
        first=t;
    }else
        if(pos>0){
            for(i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            if(p!=NULL){
                t->next=p->next;
                p->next=t;
            }
        }
}
void InsertLast(int val){
    struct Node *t,*last=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=val;
    t->next=NULL;
    if(first==NULL){
        first=last=t;
    }
    else{
        last=first;/* Initially last should start from first  */
        while(last->next!=NULL){
        last=last->next;/* Traverse last Pointer */
        }
        last->next=t;
        last=t;/* last Starts from t */
    }
}
void sortedInsert(struct Node *p,int val){
    struct Node*t,*q=NULL;/* q- following Pointer */
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=val;
    t->next=NULL;
    if(first==NULL){/* when t is the first node and Previously No Node Was Present */
        first=t;/*  first is Pointing To T */
    }
    else{
        while(p&&p->data<val){
        q=p;
        p=p->next;
        }
        if(p==first){/* when the val is smaller than the first node such that new node should get inserted in infront of first Node */
            t->next=first;
            first=t;
        }
        else{/*when the val is greater than first Node but maybe smaller or greater in following nodes */
        t->next=q->next;
        q->next=t;
        q=t;
        }
    }
}
int main(int argc, const char * argv[]) {
//     insert code here...
    int A[]={10,13,30,42,50};
    create(A,5);
    display(first);/* Before Inserting */
    printf("\n");
    insert_Pos(first, 2, 25);
    display(first);/* After Inserting */
    printf("\n");
    InsertLast(55);
    InsertLast(56);
    display(first);
    printf("\n");
    sortedInsert(first, 1);/* Inserted in front of First Node */
    sortedInsert(first,53);
    display(first);
    printf("\n");
    return 0;
}



