//
//  main.c
//  Count Sort
//
//  Created by Bikramjit Saha on 12/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int findMax(int A[],int n){
    int i,max;
    max=INT32_MIN;
    for (i=0; i<n; i++) {
        if (A[i]>max) {
            max=A[i];
        }
    }
    return max;
}
void CountSort(int A[],int n){
    int i,j,maxEle,*c;
    maxEle=findMax(A,n);
    c=(int*)malloc((maxEle+1)*sizeof(int));
    for (i=0; i<maxEle+1; i++) {
        c[i]=0;
    }
    for (i=0; i<n; i++) {
        c[A[i]]++;
    }
    i=0;j=0;
    while (j<maxEle+1) {
        if (c[j]>0) {
            A[i++]=j;
            c[j]--;
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
    // insert code here...
    int A[]={6,3,9,10,15,6,8,12,3,6};
    CountSort(A, 10);
    Display(A, 10);
    return 0;
}
