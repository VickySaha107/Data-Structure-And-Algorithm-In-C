//
//  main.c
//  Max Element in a LinkList
//
//  Created by Bikramjit Saha on 15/05/20.
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
int Max(struct Node*p){
    int m=INT32_MIN;
    while (p!=NULL) {
        if(m<p->data)
        m=p->data;
        p=p->next;
    }
    return m;
}
int RMax(struct Node*p){
    int m=INT32_MIN;
    if(p==0)
        return INT32_MIN;
    else
        m=Max(p->next);
    return m>p->data?m:p->data;/*Ternary Operator Used */
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={7,1,5,9,10,4};
    create(A,6);
    display(first);
    printf("\n");
    printf("The Max Element is %d \n",Max(first));
    printf("The Recursive Max Element is %d \n",RMax(first));
    return 0;
}
