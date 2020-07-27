//
//  main.c
//  Shell Sort
//
//  Created by Bikramjit Saha on 15/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void ShellSort(int A[],int n){
    int gap,i,j=0,temp;
    for (gap=n/2; gap>=1; gap=gap/2) {
        for (i=gap; i<n; i++) {
            temp=A[i];
            j=i-gap;// Initailly j start from 0
            while (j>-1 && A[j]>temp) {
                // Copy and adjust the element and check back the gap is matching with current gap if it matches means more than two elements need to be compared
                A[j+gap]=A[j];
                j=j-gap;
            }
            // when j is less than -1 that means j is getting outside the array so j is negative of present gap (In our example,j in pass 1 is -5 after getting out of array) so we need to balance it by adding current gap and initialise the temp value
            A[j+gap]=temp;
        }
    }
}
void Dispaly(int A[],int n){
    for (int i=0; i<n ; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[]={9,5,16,8,13,6,12,10,4,2,3};
    int n=sizeof(A)/sizeof(int);
    ShellSort(A, n);
    Dispaly(A, n);
    return 0;
}
