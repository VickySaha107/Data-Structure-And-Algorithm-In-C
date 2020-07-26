//
//  main.c
//  ReverseArray
//
//  Created by Bikramjit Saha on 26/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct array {
    int A[10];
    int size;
    int length;
};
void Display(struct array arr){
    printf("The Elements are: " );
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}
void Reverse(struct array *arr){
    int*B=(int*)malloc(arr->length*sizeof(int));
    for(int i=arr->length-1,j=0;i>=0;j++,i--)
        B[j]=arr->A[i];
    for(int i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}void swap(int*x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Reverse1(struct array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--)
        swap(&arr->A[i],&arr->A[j]);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct array arr={{1,3,4,2,5},10,5};
    Reverse(&arr);
    Reverse1(&arr);
    Display(arr);
    printf("\n");
    return 0;
}
