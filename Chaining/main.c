//
//  main.c
//  Chaining
//
//  Created by Bikramjit Saha on 17/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
 
}*first=NULL;
void sorted_insert(struct node **h,int x)
{
  struct node *t,*q=NULL,*p=*h;
  t=(struct node *)malloc(sizeof(struct node ));
  t->data=x;
  t->next=NULL;
  if(*h==NULL)
  *h=t;
  else
  {
    while(p!=NULL && p->data<x)
    {
      q=p;
      p=p->next;
    }
    if(p==*h)
    {
      t->next=*h;
      *h=t;
    }
    else
    {
      t->next=q->next;
      q->next=t;
    }
  }
 
}
 
struct node* LSearch(struct node*p,int key){
    struct node *q=NULL;
    while(p){
        if(key==p->data){
            q->next=p->next;/*Improving Linear Search using Move To Head Approach */
            p->next=first;
            first=p;
            return p;
        }
        else
            q=p;
            p=p->next;
    }
    return NULL;
}
// hash function generating index
int hash(int key)
{
  return key%10;
}
void insert(struct node **h,int key)
{
  int index=hash(key);
  sorted_insert(&h[index],key);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct node *ht[10];

    int i;
// Initialize Null to Empty Hash Table
    for(i=0;i<10;i++){
        
        ht[i]=NULL;
    }

    insert(ht,10);

    insert(ht,12);

    insert(ht,22);

    struct node *result=LSearch(ht[hash(22)],22); //perform search

    if(result)
        printf("Element is found:%d \n",result->data);

    else
        printf("Not Found\n");
    
    return 0;
}
