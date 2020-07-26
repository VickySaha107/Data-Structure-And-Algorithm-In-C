//
//  main.c
//  MinHeap
//
//  Created by Bikramjit Saha on 08/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>
/**
 Time complexity in Inserting node is always O(logn) such that there should be no space in between arrays
 */

void InsertMinHeap(int H[],int size){
    int temp,i=size;
    temp=H[size];
    while (i>1 && temp<H[i/2]) {
        H[i]=H[i/2];// copy the element to nearest vacant place
        i=i/2;
    }
    
    H[i]=temp;

}
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int DeleteMinHeap(int H[],int size){
    int i,j,str;
    str=H[1];
    H[1] =H[size];
    H[size]=str;// deleted val will go at the last place
    i=1;j=i*2;
    while (j<=size-1) {
        if (j<size-1 && H[j+1]<H[j]) {
            j=j+1;
        }
        if (H[i]>H[j]) {
            swap(&H[i],&H[j]);
//            temp=H[i];
//            H[i]=H[j];
//            H[j]=temp;
            i=j;
            j=2*i;// j should be at left child of i.
        }else
            break;
    }
    return str;
}
void Min_Heapify(int H[],int i,int size){
    int temp;
    int LCI=2*i;
    int RCI=2*i+1;
   int smallest=i;
    if (LCI<=size && H[LCI]<H[smallest]) {
        smallest=LCI;
    }
    if (RCI<=size && H[RCI]<H[smallest]) {
            smallest=RCI;
    }
    if (smallest!=i) {
        temp=H[i];
        H[i]=H[smallest];
        H[smallest]=temp;
        Min_Heapify(H, smallest, size);
    }
    
}
void display(int H[],int size){
    // ignore 0 in display
    // Result Min Heap-> 5 10 30 25 20 40 35
    for (int i=1; i<=size; i++) {
        printf("%d ",H[i]);
    }
    printf("\n");
}
void Build_minHeap(int H[],int size){
    for (int i=size/2;i>=1; i--) {
        Min_Heapify(H, i, size);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    /**
     Time complexity of Creating one node in Heap is O(logn), for creating n such node T.C-O(nlogn)
     */
    int H[]={0,10,20,30,25,5,40,35};
//    Build_minHeap(H, 7);
//    display(H, 7);
    for (int i=2; i<=7; i++) {
        InsertMinHeap(H, i);
    }
    display(H, 7);

    printf("MinHeap Sort:\n");
    for (int i=7; i>1; i--) {

       DeleteMinHeap(H, i);
    }
   display(H, 7);
   
    return 0;
}
