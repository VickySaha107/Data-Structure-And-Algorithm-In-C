//
//  main.c
//  Selection Sort
//
//  Created by Bikramjit Saha on 10/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void Swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void SelectionSort(int A[],int n){
    int i,j,k;
    for (i=0; i<n-1; i++) {
        j=i;
        for (k=i+1; k<n; k++) {
            if (A[k]<A[j]) {
                j=k;
            }
        }
         Swap(&A[i],&A[j]);
    }
}
void display(int A[],int n){
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={8,6,3,2,5,4};
    SelectionSort(A, 6);
    display(A, 6);
    return 0;
}
