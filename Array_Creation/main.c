//
//  main.c
//  Array_Creation
//
//  Created by Bikramjit Saha on 23/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct array {
    int A[14];
    int size;
    int length;
};
void add_append(struct array *arr,int x){
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}
void insert(struct array *arr,int element,int index){
    if(index>=0||arr->length<arr->size)
    for(int i=arr->length;i>index;i--)
        arr->A[i]=arr->A[i-1];
    arr->A[index]=element;
    arr->length++;
}
void Display(struct array arr){
    printf("The Elements are: ");
for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
    
}
int delete(struct array *arr,int index){
    int copy=0;
    if(index>=0&&index<arr->length){
        copy=arr->A[index];
        for(int i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
    arr->length--;
    return copy;
    }
    return 0;//if index not found return 0
}
void Swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct array *arr,int key){
    for (int i=0;i<arr->length; i++)
        if(key==arr->A[i]){
            Swap(&arr->A[i], &arr->A[0]);
            return 0;
            
        }
    return -1;
}
int BinarySearch(struct array arr,int key){
    int low,mid,high;
    low=0;
    high=arr.length-1;
    while(low<=high){
        mid =(low+high)/2;
          if(key==arr.A[mid])
        return mid;
          else if(key<arr.A[mid])
              high=mid-1;
        else
            low =mid+1;
    }
    return -1;
}
int RBinarySearch(struct array *arr,int low,int high,int key){
    int mid;
    if(low<=high){
    mid =(low+high)/2;
        if(key==arr->A[mid])
        return mid;
    else if(key<arr->A[mid])
        return RBinarySearch(arr,low,mid-1,key );
        else
            return RBinarySearch(arr,mid+1,high,key);
    }
    return -1;
}
int Get(struct array arr,int index){
    if(index>=0&&index<arr.length){
    return arr.A[index];
 }
    return -1;
}
void Set (struct array *arr,int index,int change){
    if(index>=0&&index<arr->length)
        arr->A[index]=change;
}
int  Max(struct array arr){
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}
int  Min(struct array arr){
   int min=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}
int sum(struct array arr){
    int total=0;
    for(int i=0;i<arr.length;i++){
        total+=arr.A[i];
    }
    return total;
}
float avg(struct array arr){
    return sum(arr)/arr.length;
}
void InsertSort(struct array *arr,int key){
   int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0&&arr->A[i]>key){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=key;
    arr->length++;
}
int IsSorted(struct array arr){
    int i;
    for(i=0;i<arr.length-1;i++)
        if(arr.A[i]>arr.A[i+1]){
    return 0;
    }
    return 1;
}
void Rearrange(struct array *arr){
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j){
    while(arr->A[i]<0)
        i++;
    while (arr->A[j]>=0)
        j--;
    if(i<j)
    Swap(&arr->A[i],&arr->A[j]);
    }
}
struct array* mergeArray(struct array *arr1,struct array *arr2){
    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
    else
               arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
}
struct array* Union(struct array *Uarr1,struct array *Uarr2){
    int i,j,k;
    i=j=k=0;
    struct array *Uarr3=(struct array *)malloc(sizeof(struct array));
    while(i<Uarr1->length&&j<Uarr2->length){
    if(Uarr1->A[i]<Uarr2->A[j])
        Uarr3->A[k++]=Uarr1->A[i++];
    else if(Uarr2->A[j]<Uarr1->A[i])
        Uarr3->A[k++]=Uarr2->A[j++];
    else{
        Uarr3->A[k++]=Uarr1->A[i++];/* copy only one of the Array's element */
        j++;
    }
}
    for(;i<Uarr1->length;i++)
        Uarr3->A[k++]=Uarr1->A[i];
    for(;j<Uarr2->length;j++)
        Uarr3->A[k++]=Uarr2->A[j];
    Uarr3->length=k;
    Uarr3->size=10;
    return Uarr3;
}
struct array* Intersection(struct array *Iarr1,struct array *Iarr2){
    int i,j,k;
    i=j=k=0;
    struct array *Iarr3=(struct array *)malloc(sizeof(struct array));
    while(i<Iarr1->length&&j<Iarr2->length){
    if(Iarr1->A[i]<Iarr2->A[j])
        i++;
    else if(Iarr2->A[j]<Iarr1->A[i])
        j++;
    else if(Iarr1->A[i]==Iarr2->A[j]){
        Iarr3->A[k++]=Iarr1->A[i++];/* copy only one of the Array's element */
        j++;
    }
}
    Iarr3->length=k;
    Iarr3->size=10;
    return Iarr3;
}
struct array* Difference(struct array *Darr1,struct array *Darr2){
    int i,j,k;
    i=j=k=0;
    struct array *Darr3=(struct array *)malloc(sizeof(struct array));
    while(i<Darr1->length&&j<Darr2->length){
    if(Darr1->A[i]<Darr2->A[j])
        Darr3->A[k++]=Darr1->A[i++];
    else if(Darr2->A[j]<Darr1->A[i])
        j++;
    else{
        i++;
        j++;
    }
}
    for(;i<Darr1->length;i++)
        Darr3->A[k++]=Darr1->A[i];
    
    Darr3->length=k;
    Darr3->size=14;
    return Darr3;
}
int main() {
    // insert code here...
//   struct array arr={{-2,3,-4,5,-6,9},10,6};
//     struct array arr1={{2,6,10,15,25,},10,5};/*arr1 must be sorted*/
//     struct array arr2={{3,4,7,18,20},10,5};/*arr2 must be sorted*/
//     struct array *arr3;
//    struct array Uarr1={{3,4,5,6,10},10,5};/*Uarr1 must be sorted*/
//    struct array Uarr2={{2,4,5,7,12},10,5};/*Uarr2 must be sorted*/
//    struct array *Uarr3;
        struct array Iarr1={{3,4,4,5,5,6,7,10},10,8};/*Uarr1 must be sorted*/
        struct array Iarr2={{2,4,5,7,7,12},10,6};/*Uarr2 must be sorted*/
         struct array *Iarr3;
//      struct array Darr1={{3,4,5,6,10},10,5};/*Uarr1 must be sorted*/
//      struct array Darr2={{2,4,5,7,12},10,5};/*Uarr2 must be sorted*/
//      struct array *Darr3;
   /*insert(&arr, 3, 3);
    add_append(&arr,7);*/
    /*printf("%d\n ", delete(&arr, 3));*/
   /* printf("%d \n",LinearSearch(&arr,7));*/
    /*printf("%d \n",BinarySearch(arr, 5));*/
    /*printf("%d \n",RBinarySearch(&arr,0,arr.length,7));*/
   /* printf("%d\n",Get(arr,3));*/
    /*Set(&arr, 3, 15);*/
    /*printf("%d\n",Max(arr));*/
    /*printf("%d\n",Min(arr));*/
    /*printf("%d\n",sum(arr));*/
    /*printf("%f\n",avg(arr));*/
//    InsertSort(&arr,8);
//    printf("%d \n", IsSorted(arr));
//    Rearrange(&arr);
//    Display(arr);
//    arr3=mergeArray(&arr1, &arr2);
//    Display(*arr3);
//    Uarr3=Union(&Uarr1,&Uarr2);
//    Display(*Uarr3);
   Iarr3=Intersection(&Iarr1,&Iarr2);
       Display(*Iarr3);
//    Darr3=Difference(&Darr1,&Darr2);
//    Display(*Darr3);
    printf("\n");
    return 0;
}
