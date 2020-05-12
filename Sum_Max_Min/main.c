//
//  main.c
//  Sum_Max_Min
//
//  Created by Bikramjit Saha on 29/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
struct array {
    int A[10];
    int length;
    int size;
};
void Sum(struct array arr,int sum ){
    int i,j;
    for(i=0;i<arr.length-1;i++){
        for (j=1; j<arr.length; j++) {
            if(arr.A[i]+arr.A[j]==arr.A[sum])
            printf("%d+%d=%d\n",arr.A[i],arr.A[j],arr.A[sum]);
        }
    }
}
void SumHashTable(struct array arrH,struct array Hash,int sum){
    int i;
    for(i=0;i<arrH.length;i++){
        if(Hash.A[sum-arrH.A[i]]!=0&&Hash.A[sum-arrH.A[i]]>=0){
            printf("The pair is %d+%d=%d\n",arrH.A[i],sum-arrH.A[i],sum);
        }
        Hash.A[arrH.A[i]]++;
    }
}
void Sum_Sorted(struct array arrS,int sum){
    int i,j;
    i=0;
    j=arrS.length-1;
    while(i<j){
        if(arrS.A[i]+arrS.A[j]==arrS.A[sum]){
            printf("The pair is %d+%d=%d\n",arrS.A[i],arrS.A[j],arrS.A[sum]);
            i++;
            j--;
        }
        else if(arrS.A[i]+arrS.A[j]<arrS.A[sum]){
            i++;
        }
        else
            j--;
    }
}
void max_min(struct array arrM){
    int i,min,max;
    min=arrM.A[0];
    max=arrM.A[0];
    for (i=1; i<arrM.length; i++) {
        if(arrM.A[i]<min){
        min=arrM.A[i];
      }
        else if(arrM.A[i]>max){
        max=arrM.A[i];
      }
   }
    printf("The Min No is %d\nThe Max No is %d\n",min,max);
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    struct array arr={{6,3,8,10,16,7,5,2,9,14},10,10};
//    Sum(arr,10);
//    struct array arrH={{6,3,8,10,16,7,5,2,9,14},10,10};
//    struct array Hash={{},17,17};
//    SumHashTable(arrH,Hash,10);
//    struct array arrS={{1,3,4,5,6,8,9,10,12,14},10,10};
//    Sum_Sorted(arrS,10);
    struct array arrM={{5,8,3,9,6,2,10,-1,4},10,10};
    max_min(arrM);
    printf("");
    return 0;
}
