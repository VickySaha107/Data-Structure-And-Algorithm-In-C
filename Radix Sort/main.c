//
//  main.c
//  Radix Sort
//
//  Created by Bikramjit Saha on 14/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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



int count(int m){
    int c = 0;
    while(m != 0)
    {
        m = m/10;
        c++;
        
    }
    return c;
    
}



void Insert(struct Node** bins,int val,int index){
    struct Node *t= (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    if(bins[index] == NULL){
        bins[index] = t;

    }
    else{
        struct Node *q = bins[index];
        while(q->next != NULL)
        {
            q = q->next;

        }
              q->next = t;
    }
}


// deletion will be done in FIFO fashion

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




void Radixsort(int A[],int n){
    int max = findMax(A,n);

    int no_of_passes = count(max);
// Range of Decimal number is 0-9 so Size is 10
    // Double Pointer because bins is getting modified in each pass
    struct Node** bin = (struct Node**)malloc(10*sizeof(struct Node*));

    for(int i = 0;i < 10;i++) // initializing bins

    {

    bin[i] = NULL;

    }

    // update bins and A for no_of_passes times

    for(int pass = 0;pass < no_of_passes;pass++)

    {

    // update bins



    for(int i = 0;i < n;i++)

    {
    // convert index into integer
    int bin_index = (int)(A[i]/pow(10,pass))%10;

    Insert(bin,A[i],bin_index);

    }

    // update A

    int i = 0;

    int j = 0;



    while(j < 10)

    {

    if(bin[j] != NULL)

    {

        A[i++] = Delete(&bin[j]);

    }else
        
        j++;
        
    }
    }
        free(bin);

}


void Display(int A[],int n){
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={237,146,259,348,152,163,235,48,36,62};
    int n=sizeof(A)/sizeof(int);
    Radixsort(A, n);
    Display(A, n);
    return 0;
}
