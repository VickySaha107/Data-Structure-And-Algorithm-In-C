//
//  main.c
//  Delete Node In A  LinkList
//
//  Created by Bikramjit Saha on 17/05/20.
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
int delete(struct Node*p,int pos){
    struct Node *q;
    p=first;
    q=NULL;
    int store=-1,i;
    if (pos<1) {
        return -1;
    }
    else if(pos==1){
            first=first->next;
            store=p->data;
            free(p);
            return store;
        }
    else
        for (i=0; i<pos-1 && p; i++) {
            q=p;
            p=p->next;
        }
    if(p){
    q->next=p->next;
    store=p->data;
    free(p);
    }
    return store;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={3,5,7,9,12,15};
    create(A,6);
    display(first);
    printf("\n");
    printf("The Deleted Element is %d\n",delete(first, 4));
    display(first);
    printf("\n");
    return 0;
}
