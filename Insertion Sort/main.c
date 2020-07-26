//
//  main.c
//  Insertion Sort
//
//  Created by Bikramjit Saha on 09/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void InsertionSort(int A[],int size){
    int i,j,x;
    for (i=1; i<size; i++) {
        x=A[i];
        j=i-1;
        while (j!=-1&&A[j]>x) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
void Display(int A[],int n){
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={8,5,7,3,2};
    InsertionSort(A,5);
    Display(A, 5);
    printf("\n");
    return 0;
}
