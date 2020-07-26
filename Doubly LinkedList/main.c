//
//  main.c
//  Doubly LinkedList
//
//  Created by Bikramjit Saha on 26/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
}*Head=NULL;
void create(int A[],int n){
    struct Node*t,*last;
    int i;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head->prev=NULL;
    last=Head;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
int count(struct Node*p){
    int c=0;
    while (p) {
        p=p->next;
        c++;
    }
    return c;
}
void Display(struct Node*p){
    while (p) {
        printf("%d ",p->data);
        p=p->next;
    }
}
void Insert(struct Node*p,int pos,int val){
    struct Node*t;int i;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=val;
    if (pos<0||pos>count(Head)) {
        return;
    }
    else if (pos==0){
        t->prev=NULL;
        t->next=Head;
        Head->prev=t;
        Head=t;
    }
    else{
        for (i=0; i<pos-1; i++) {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
        t->prev=p;
        if (p->next!=NULL) {
            p->next->prev=t;
        }
    }
}
int Delete(struct Node*p,int pos){
    p=Head;
    int store=-1,i;
    if (pos<0||pos>count(Head)) {
        return -1;
    }else if (pos==1){
        Head=Head->next;
        if(Head->next!=NULL){
        Head->prev=NULL;
        }
        store=p->data;
        free(p);
    }else{
        for (i=0; i<=pos-2; i++) {
            p=p->next;
        }
        p->prev->next=p->next;
        if (p->next) {
            p->next->prev=p->prev;
        }
        store=p->data;
        free(p);
    }
    return store;
}
void Reverse(struct Node*p){
    struct Node*temp;
    p=Head;
    while(p){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
        p=p->prev;
        if (p!=NULL&&p->next==NULL) {
            Head=p;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={5,4,3,6,7};
    create(A, 5);
    printf("Length is: %d \n",count(Head));
    Display(Head);
    printf("\n");
    Reverse(Head);
    Display(Head);
    printf("\n");
    printf("The Deleted Element is %d\n",Delete(Head, 2));
    Display(Head);
    printf("\n");
    Insert(Head, 4, 10);
    Display(Head);
    printf("\n");
    return 0;
}
