//
//  main.c
//  Duplicate and Count of Sorted Array
//
//  Created by Bikramjit Saha on 28/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
struct array{
    int A[21];
    int length;
    int size;
};
void Duplicate(struct array arr){
    int last_Duplicate=0;
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]==arr.A[i+1]&&last_Duplicate!=arr.A[i]){
            printf("%d\n",arr.A[i]);
            last_Duplicate=arr.A[i];
        }
    }
}
   void Duplicate_Count(struct array arr1){
       int last_Duplicate=0;
       int i,j;
       for(i=0;i<arr1.length-1;i++){
           if(arr1.A[i]==arr1.A[i+1]&&arr1.A[i]!=last_Duplicate){
               j=i+1;
               while(j<arr1.length&&arr1.A[j]==arr1.A[i]){
                   j++;
               printf("%d is appearing %d times\n",arr1.A[i],j-i);
               last_Duplicate=arr1.A[i];
               i=j-1;/* or i=j */
           }
       }
   }
}
void Duplicate_Count_Unsorted(struct array arr3){
    int i,j,Count;
    for(i=0;i<arr3.length-1;i++){
        Count=1;
        if(arr3.A[i]!=-1){
        for(j=i+1;j<arr3.length;j++){
            if(arr3.A[i]==arr3.A[j]){
                Count++;
                arr3.A[j]=-1;
            }
        }
            if(Count>1)
            printf("%d is appearing %d times\n",arr3.A[i],Count);
        }
    }
}
/*HashTable Used For Both Sorted And Unsorted Array*/
void Duplicate_Count_Hashing(struct array arr2,struct array Hashtable){
    int i;
    for(i=0;i<arr2.length;i++){
        Hashtable.A[arr2.A[i]]++;
    }
    for(i=0;i<Hashtable.length;i++)
        if(Hashtable.A[i]>1)
            printf("%d is appearing %d times\n",i,Hashtable.A[i]);
}
    
int main(int argc, const char * argv[]) {
    // insert code here...
//    struct array arr={{3,6,8,8,10,15,15,15,20},10,10};
//    Duplicate(arr);
//    struct array arr1={{3,6,8,8,10,12,15,15,20,20},10,10};
//    Duplicate_Count(arr1);
//    struct array arr2={{3,12,8,8,10,12,15,15,20,20},10,10};
//    struct array Hashtable={{},21,21};
//    Duplicate_Count_Hashing(arr2,Hashtable);
    struct array arr3={{8,3,6,4,6,5,6,8,2,7},10,10};
    Duplicate_Count_Unsorted(arr3);
    printf("");
    return 0;
}
