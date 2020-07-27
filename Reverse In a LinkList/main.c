//
//  main.c
//  Reverse In a LinkList
//
//  Created by Bikramjit Saha on 18/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL;/* first-Global pointer */
void create(int A[],int n){
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    int i;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for (i=1; i<n; i++) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int Count(struct Node*p){
    int c=0;
    while (p) {
        c++;
        p=p->next;
    }
    return c;
}
void display(struct Node*p){
    while (p) {
         printf("%d ",p->data);
        p=p->next;
    }
}
void Reverse1(struct Node*p){
    int *A,i=0;
    p=first;
    A=(int*)malloc(sizeof(int)*Count(p));//Dynamically create a size of array in Heap equals to the number of nodes
    while (p) {
        A[i++]=p->data;
        p=p->next;
    }
    p=first;i--;
    while (p) {
        p->data=A[i--];
        p=p->next;
    }
}
void Reverse2(struct Node*p){
    struct Node*r,*q=NULL;
    p=first;
    while (p) {
        r=q;/* 3 steps req for Sliding three Pointers */
        q=p;
        p=p->next;
        q->next=r;// For Reversing Links
    }
    first=q;
}
void Reverse3(struct Node*q,struct Node*p){
    if (p) {
        Reverse3(p, p->next);//Recursive Reverse
        p->next=q;
    }
    else{
        first=q;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={2,4,6,8,16,17};
    create(A, 6);
    display(first);
    printf("\n");
    Reverse1(first);
    display(first);
    printf("\n");
    Reverse2(first);
    display(first);
    printf("\n");
    Reverse3(NULL,first);
    display(first);
    printf("\n");
    return 0;
}
