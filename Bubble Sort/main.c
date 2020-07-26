//
//  main.c
//  Bubble Sort
//
//  Created by Bikramjit Saha on 09/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void BubbleSort(int A[],int size){
    // Implementing Flag for adaptiveness in Bubble Sort
    int i,j,flag;
    for (i=0; i<size-1; i++) {
        flag=0;
        for (j=0; j<size-1-i; j++) {
            if (A[j]>A[j+1]) {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if (flag==0) {
            break;
        }
    }
}
void Display(int A[],int size){
    for (int i=0; i<size; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={8,5,7,3,2};
    BubbleSort(A, 5);
    Display(A, 5);
    return 0;
}
