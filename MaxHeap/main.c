//
//  main.c
//  MaxHeap
//
//  Created by Bikramjit Saha on 08/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
/**
 Time complexity in Inserting node is always O(logn) such that there should be no space in between arrays
 */
void InsertMaxHeap(int H[],int size){
    int temp,i=size;
    temp=H[size];
    while (i>1 && temp>H[i/2]) {
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
int DeleteMaxHeap(int H[],int size){
    // Only root element is deleted in Heap
    int i,j,str;
    str=H[1];
    H[1] =H[size];
    H[size]=str;// deleted val will go at the last place
    i=1;j=i*2;
    // j is inserting from 2 to size and after deleting decrease the heap size to size -1 and j can go upto last elmenent in array
    while(j<=size-1){
    // compare the children of current node and then compare the greatest children with current node
    if (j<size-1&&H[j+1]>H[j]){
        // when right child is greater than left child assingn j to rigth child(i.e, 2*i+1) other wise j is left child only
        j=j+1;
    }
    // when current root node is smaller than it's rigth or left child then simply swap otherwise break
    if (H[i]<H[j]) {
        // swapping of element
        swap(&H[i],&H[j]);
//        temp=H[i]; H[i]=H[j]; H[j]=temp;
        // set the pointer in current state
        i=j;
        j=2*j;
    }else
        break;
    }
    // store the delted element in a free vacant place at the end and also deleting one by one make the heap sorted (Heap Sort)
   return str;
}
void MaxHeapify(int H[],int i,int size)

{

    int L,R,Largest,temp;

    L=2*i;
    R=2*i+1;
    Largest=i;
    if(L<=size && H[Largest]<H[L])
        Largest=L;
    if(R<=size && H[R]>H[Largest])
        Largest=R;
    if(Largest!=i)
    {
        temp=H[i];

        H[i]=H[Largest];

        H[Largest]=temp;

        MaxHeapify(H,Largest,size);

    }

    return;

}

void Build_MaxHeapify(int H[],int size){
    for (int i=size/2; i>=1; i--) {
        MaxHeapify(H, i, size);
    }
}
void display(int H[],int size){
    // ignore 0 in display
    // Result Max Heap-> 40 25 35 10 5 20 30
    
    for (int i=1; i<=size; i++) {
        printf("%d ",H[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    // insert code here...
    /**
     * Time complexity of Creating one node in Heap is O(logn), for creating n such node T.C-O(nlogn)
     * T.C-> of Heapify is O(n)
     */
    int H[]={0,10,20,30,25,5,40,35};
    printf("Max Heapify:\n");
//    Build_MaxHeapify(H,7);
//       display(H, 7);

    for (int i=2; i<=7; i++) {
        InsertMaxHeap(H, i);
    }
    display(H, 7);


    printf("MaxHeap Sort:\n");
     for (int i=7; i>1; i--) {

         DeleteMaxHeap(H, i);
      }
     display(H, 7);
    


    return 0;
}
