//
//  main.c
//  Merge Sort
//
//  Created by Bikramjit Saha on 11/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
// Merging Two Sorted List Into Third Single Sorted List
void Merging(int A[],int B[],int C[],int n,int m,int size){
    int i=0,j=0,k=0;
    while (i<n && j<m) {
        if (A[i]<=B[j]) {
            C[k++]=A[i++];
        }else{
            C[k++]=B[j++];
        }
    }
    while(i<n){
        C[k++]=A[i++];
    }
    while (j<m) {
        C[k++]=B[j++];
    }
}
// Merging Two Sorted List by Taking Extra Auxilary Array and copying the sorted elements back to original array
void M_wayMerging(int A[],int low,int mid,int high){
    int i,j,k;
    int B[high+1];
    i=low;j=mid+1;k=low;
    while(i<=mid && j<=high){
        if (A[i]<A[j]) {
            B[k++]=A[i++];
        }else{
            B[k++]=A[j++];
        }
    }
    while (i<=mid) {
         B[k++]=A[i++];
    }
    while (j<=high) {
        B[k++]=A[j++];
    }
    // copy all the elements from low to high in original array
    for (int i=low; i<=high; i++) {
        A[i]=B[i];
    }
}
void IMergeSort(int A[],int n){
    int pass,i,low,mid,high;
    for (pass=2; pass<=n; pass=pass*2) {
       
        for (i=0; i+pass-1<n; i=i+pass) {
            low=i;
            high=i+pass-1;
            mid=(low+high)/2;
            M_wayMerging(A, low, mid, high);
        }
    }
    if (pass/2<n) {
        M_wayMerging(A, 0, pass/2-1, n-1);
    }
}
void RMergeSort(int A[],int low,int high){
    int mid=(low+high)/2;
    if(low<high){
    RMergeSort(A, low, mid);
    RMergeSort(A, mid+1, high);
    M_wayMerging(A, low, mid, high);
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
    int A[]={8,3,7,4,9,2,6,5,1};
    IMergeSort(A, 9);
//    RMergeSort(A,0,9);
//    int B[]={2,4,6,8,10};
//    int C[]={};
//    Merging(A, B, C ,4, 4, 8);
    Display(A, 9);
    return 0;
}
