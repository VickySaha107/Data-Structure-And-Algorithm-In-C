//
//  main.c
//  Display Circular LinkedList
//
//  Created by Bikramjit Saha on 25/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*Head=NULL;
void create(int A[],int n){
    struct Node*t,*last;
    int i;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=Head;
        last->next=t;
        last=t;
    }
}
void Display(struct Node*p){
    do {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=Head);
}
void DisplayR(struct Node*p){
    printf("%d ",p->data);
    if (p->next!=Head) {
        DisplayR(p->next);
    }
}
void DisplayFlag(struct Node*p){
    static int flag=0;
    if (p!=Head||flag==0) {
        flag=1;
        printf("%d ",p->data);
        DisplayFlag(p->next);
    }
    flag=0;/* when we call for next time we have to make the flag value as 0 */
}
int count(struct Node*p){
    int c=0;
    do {
        p=p->next;
        c++;
    } while (p!=Head);
    return c;
}
void Insert(struct Node*p,int pos,int val){
    struct Node*t;int i;
    if (pos<0||pos>count(Head)) {
        return;
    }
    if (pos==0) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=val;
        if(Head==NULL){
            Head=t;
            Head->next=t;
        }else{
            p=Head;
            while (p->next!=Head) {
                p=p->next;
            }
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }else{
        p=Head;
        for (i=0; i<pos-1; i++) {
            p=p->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=val;
        t->next=p->next;
        p->next=t;
    }
}
int Delete(struct Node*p, int pos){
    struct Node*q=NULL;
    p=Head;
    int store=-1,i;
    if(pos<1||pos>count(Head))
        return -1;
    if (pos==1) {
        while (p->next!=Head) {
            p=p->next;
        }
        if(p==NULL){
            free(Head);
            Head=NULL;
        }
    else{
        p->next=Head->next;
        store=Head->data;
        free(Head);
        Head=p->next;
    }
    }else{
        for (i=0; i<pos-1; i++) {
            q=p;
            p=p->next;
        }
    q->next=p->next;
    store=p->data;
    free(p);
    }
    return store;
}
int main(int argc, const char * argv[]) {
//     insert code here...
    int A[]={3,4,5,1,2};
    create(A, 5);
    Display(Head);
    printf("\n");
    DisplayR(Head);
    printf("\n");
    DisplayFlag(Head);
    printf("\n");
    Insert(Head, 4, 10);
    Display(Head);
    printf("\n");
    Delete(Head,4);
    Display(Head);
    printf("\n");
    return 0;
}
