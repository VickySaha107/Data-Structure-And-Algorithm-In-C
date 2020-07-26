//
//  main.c
//  Count And Sum In A Link List
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
int count (struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int Rcount(struct Node *p){
   if(p==NULL)
       return 0;
    else
      return  Rcount(p->next)+1;
}
int Add(struct Node*p){
    int sum=0;
    while(p/*or p!=NULL or 0 */){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int RAdd(struct Node *p){
    if(p==NULL)
        return 0;
    else
        return RAdd(p->next)+p->data;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={5,4,3,2,1};
    create(A, 5);
    display(first);
    printf("\n");
    printf("Count is is %d ",count(first));
    printf("\n");
    printf("Recurcive Count is %d ",Rcount(first));
    printf("\n");
    printf("Total is %d ",Add(first));
    printf("\n");
    printf("Recursive Total is %d ",RAdd(first));
    printf("\n");
    return 0;
}
