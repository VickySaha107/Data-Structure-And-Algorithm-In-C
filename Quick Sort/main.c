//
//  main.c
//  Quick Sort
//
//  Created by Bikramjit Saha on 10/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int A[],int low,int high){
    int pivot=A[low];
    int i,j;
    i=low;
    j=high;
    
    while (i<j) {
        do {
            i++;
        } while (A[i]<=pivot);// termination condition ( actually i should search for greater element than pivot)
        do {
            j--;
        } while (A[j]>pivot);// termination condition ( actually j should search for smaller element than pivot)
        if (i<j) {
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[low],&A[j]);// come out of the loop and swap low with j

    return j;// index j holds the sorted position of pivot element
    
}
void QuickSort(int A[],int low,int high){
    int j;
    if (low<high) {
       j= partition(A, low, high);
        QuickSort(A, low, j);// perform quicksort on left partition (in left partition high i.e, j acts as infinity
        QuickSort(A, j+1, high);// perform quicksort on right partition
    }
}
void Display(int A[],int n){
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={10,16,8,12,15,6,3,9,5},n=10;// take one size greater for infinity
    
    QuickSort(A,0,n-1);
  
    Display(A, n-1);// avoid displaying infinity
    
    return 0;
}
