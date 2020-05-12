//
//  main.c
//  SwapNumbers
//
//  Created by Bikramjit Saha on 15/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void swap(int *num1,int *num2){
    int temp;
temp=*num1;
*num1=*num2;
*num2=temp;
}
int main() {
    int a=3;int b=5;
    swap(&a,&b);
    // insert code here...
    printf("%d %d\n",a,b);
    
}
