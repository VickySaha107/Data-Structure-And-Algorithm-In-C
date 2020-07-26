//
//  main.c
//  Detect Loop In a LinkedList
//
//  Created by Bikramjit Saha on 21/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL    ;
void create(int A[],int n){
    struct Node*t,*last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
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
int IsLoop(struct Node*f){
    struct Node*p,*q;
    p=q=f;
    do {
        p=p->next;
           q=q->next;
           if (q!=NULL) {
               q=q->next;
           }else{
               q=NULL;
           }
    } while (p&&q&&p!=q);
           return p==q?1:0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Node*t1 = NULL,*t2 = NULL;
    int A[]={8,5,4,7,3,3};
    create(A,6);
    Display(first);
    printf("\n");
    t1=first->next->next;
    t2=first->next->next->next->next->next;
    t2->next=t1;
    if(IsLoop(first))
        printf("Loop is Detected \n");
    else
        printf("Loop is Not Detected \n");
    return 0;
}
