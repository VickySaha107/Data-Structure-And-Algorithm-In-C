//
//  main.c
//  Finding In A MIddlle Of A LinkedList
//
//  Created by Bikramjit Saha on 04/06/20.
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
int middle(struct Node*p){
    struct Node*q =first;
    while (q->next) {
        q=q->next;
        if (q->next) {
            q= q->next;
        }
        p=p->next;
    }
    return p->data;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={5,6,3,9,10,4,2};
    create(A, 7);
    printf("The Middle Element is %d \n",middle(first));
    display(first);
    printf("\n");
    return 0;
}
