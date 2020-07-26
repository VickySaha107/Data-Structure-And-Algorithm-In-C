//
//  main.c
//  Display Link List
//
//  Created by Bikramjit Saha on 14/05/20.
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
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void RDisplay(struct Node *P){
    if (P!=NULL) {
        printf("%d ",P->data);
        RDisplay(P->next);
    }
}
void RevDisplay(struct Node *P){
    if (P!=NULL) {
        RDisplay(P->next);
        printf("%d ",P->data);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={6,5,4,3,2};
    create(A,5);
    Display(first);
    RDisplay(first);
    printf("\n");
    RevDisplay(first);
    printf("\n");
}
