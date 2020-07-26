//
//  main.c
//  Single_Multiple  Missing Element
//
//  Created by Bikramjit Saha on 28/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
struct array{
    int A[14];
    int length;
    int size;
};
void singleSearch(struct array arr){
    int low=arr.A[0];
int diff=low-0;
    int i;
    for(i=0;i<arr.length;i++){
        if(arr.A[i]-i!=diff){
            printf("Missing Element is:%d ",i+diff);
            break;
        }
    }
}
void multipleSearch(struct array arr1){
    int low=arr1.A[0];
int diff=low-0;
    int i;
    for(i=0;i<arr1.length;i++){
        if(arr1.A[i]-i!=diff){
            while(diff<arr1.A[i]-i){
            printf("Missing Element is:%d \n",i+diff);
            diff++;
            }
        }
    }
}
void searchHashing(struct array arrH,struct array Hastable){
    int low=1,i;
    for(i=0;i<arrH.length;i++){
        Hastable.A[arrH.A[i]]++;
    }
    for(i=low;i<=Hastable.length;i++){
        if(Hastable.A[i]==0)
        printf("Missing Element is:%d\n",i);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    struct array arr={{6,7,8,9,10,11,13,14,15,16,17},11,12};
//    singleSearch(arr);
//    struct array arr1={{6,7,8,9,11,12,15,16,17,18,19},11,14};
//    multipleSearch(arr1);
    struct array arrH={{3,7,4,9,12,6,1,11,2,10},10,12};
    struct array Hastable={{},12,12};
    searchHashing(arrH,Hastable);
    printf("\n");
    return 0;
}
