//
//  main.c
//  Find Missing Element
//
//  Created by Bikramjit Saha on 28/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
int Missing_Element(int arr[],int length){
    int m=length+1;/*acatual size is Lenght+1 since Number is Missing*/
   int Total=m*(m+1)/2;
    int sum=0;
    for(int i=0;i<length;i++)
        sum+=arr[i];
      return Total-sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[]={1,3,4,5,6};
   
     int length=sizeof(arr)/sizeof(arr[0]);
     printf("The Missing  Element Is:%d",Missing_Element(arr,length));
    
    printf("\n");
      return 0;
}
 
