//
//  main.c
//  Searching In a LinkList
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
struct Node* LSearch(struct Node*p,int key){
    struct Node *q=NULL;
    while(p){
        if(key==p->data){
            q->next=p->next;/*Improving Linear Search using Move To Head Approach */
            p->next=first;
            first=p;
            return p;
        }
        else
            q=p;
            p=p->next;
    }
    return NULL;
}
struct Node* Rsearch(struct Node*p,int key){
    if(p==NULL)
        return  NULL;
    else if(key==p->data)
            return p;
    else
        return Rsearch(p->next,key);
        
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Node*tempL,*tempR;
    int A[]={5,7,23,15,6,3};
    create(A, 6);
    tempL=LSearch(first,15);
    if(tempL)
        printf("Element %d is found Linearly \n",tempL->data);
    else
        printf("Element Not Found\n");
    display(first);
    printf("\n");
    tempR=Rsearch(first, 23);
    if (tempR)
        printf("Element %d is found Recursively \n",tempR->data);
    else
        printf("Element Not Found\n");
    return 0;
}
