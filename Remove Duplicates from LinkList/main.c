//
//  main.c
//  Remove Duplicates from LinkList
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
void display(struct Node*p){
    while (p) {
         printf("%d ",p->data);
        p=p->next;
    }
}
void removeDup_S(struct Node*p){
    struct Node*q;
    p=first;
    q=first->next;
    while (q) {
        if (p->data==q->data) {
            p->next=q->next;
            free(q);
            q=p->next;
        }
        else{
            p=q;
            q=q->next;
        }
    }
}
void removeDup_US(struct Node*p){
    struct Node* curr,*dup;/*dup is used to store address of curr next Node  having same data with previous Node p */
    p=first;
    while (p&&p->next!=NULL) {
        curr=p;
        while (curr&&curr->next!=NULL) {
            if (p->data==curr->next->data) {
                dup=curr->next;
                curr->next=dup->next;
                free(dup);
            }
            else
            {
                curr=curr->next;
            }
        }
        p=p->next;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={1,2,3,2,4,1};
    create(A, 6);
    display(first);
    printf("\n");
//    removeDup_S(first);
//    display(first);
//    printf("\n");
    removeDup_US(first);
    display(first);
    printf("\n");
    return 0;
}
