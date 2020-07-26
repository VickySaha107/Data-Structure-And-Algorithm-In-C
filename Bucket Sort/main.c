//
//  main.c
//  Bucket Sort
//
//  Created by Bikramjit Saha on 13/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

int findMax(int A[],int n){
    int max=INT32_MIN;
    int i;
    for (i=0; i<n; i++) {
        if (A[i]>max) {
            max=A[i];
        }
    }
    return max;
}
/**
 * Both Insert And Delete Function Are Having Pointer to Pointer (i.e, double pointer ) of type Node because the bins are getting modified after insertion and deletion of nodes
 * when we pass double pointers that means we pass entire array of pointers
 */
void Insert(struct Node**head,int val){
    struct Node*p=*head;
    if (*head==NULL) {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=val;
        p->next=NULL;
        *head=p;
    }
    if (p!=NULL) {
        struct Node*q=p;
        while (q->next!=NULL) {
            struct Node*t=(struct Node*)malloc(sizeof(struct Node));
            t->data=val;
            t->next=NULL;
            q->next=t;
        }
    }
}

int Delete(struct Node**head){
    struct Node*p=*head;
    int str=-1;
    if (!*head) {
        return -1;
    }
    if (p!=NULL) {
        *head=(*head)->next;
        str=p->data;
        free(p);
    }
   return str;
}
void Binsort(int A[],int n){
    int maxEle,i,j;
    struct Node**bin;
    maxEle=findMax(A,n);
    bin=(struct Node**)malloc((maxEle+1)*sizeof(struct Node*));
    for (i=0; i<maxEle+1; i++) {
        bin[i]=NULL;
    }
    for (i=0; i<n; i++) {
        Insert(&bin[A[i]],A[i]);
    }
    i=0;j=0;
    while (j<maxEle+1) {
        if (bin[j]!=NULL) {
           A[i++]=Delete(&bin[j]);
        }else
            j++;
    }
}
void Display(int A[],int n){
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
//     insert code here...
    int A[]={8,3,7,4,9,2,6,5};
    int n=sizeof(A)/sizeof(int);
    Display(A,n);
    Binsort(A,n);
    Display(A,n);

    return 0;
}

