//
//  main.c
//  Check LinkList is Sorted or Not
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
int Issorted(struct Node*p){
    p=first;
    int min_val=INT32_MIN;
    while (p) {
        if (p->data<min_val) {
            return 0;/* false */
        }
        else
            min_val=p->data;
        p=p->next;
    }
    return 1;/* true */
}
int Issorted_usingPTR(struct Node*p){
    struct Node*q;
    p=first;
    q=first->next;
    while (q) {
        if (q->data<p->data) {
            return 0;/* false */
        }
        else
            p=q;
        q=q->next;
    }
    return 1;/* true */
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={3,4,5,17,10};
    create(A, 5);
    if(Issorted(first)){
    printf("Sorted \n");/* true */
    }else{
    printf("Not Sorted \n");/* false */
    }
    display(first);
    printf("\n");
    if(Issorted_usingPTR((first))){
    printf("Sorted \n");/* true */
    }else{
    printf("Not Sorted \n");/* false */
    }
    display(first);
    printf("\n");
    return 0;
}
