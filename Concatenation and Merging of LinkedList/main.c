//
//  main.c
//  Concatenation and Merging of LinkedList
//
//  Created by Bikramjit Saha on 21/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL,*second=NULL,*third=NULL;/* Global pointer */
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
void create2(int B[],int n){
    struct Node *t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    int i;
    second->data=B[0];
    second->next=NULL;
    last=second;
    for (i=1; i<n; i++) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node*p){
    while (p) {
        printf("%d ",p->data);
        p=p->next;
    }
}
void Concat(struct Node*p){
    p=first;
    while (p->next!=NULL) {
        p=p->next;
    }
    p->next=second;
    second=NULL;
}
void Merge(struct Node*p,struct Node*q){
    struct Node*last;
    if(p->data<q->data){
       third=last=p;
       p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p&&q){
        if (p->data<q->data) {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    if(q!=NULL)
        last->next=q;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={2,8,10,15,17};
    int B[]={4,7,12,14,16};
    create(A, 5);
    Display(first);
    printf("\n");
    create2(B, 5);
    Display(second);
    printf("\n");
    Merge(first,second);
    Display(third);
    printf("\n");
//  Concat(first);
//  Display(first);
//  printf("\n");
    return 0;
}
