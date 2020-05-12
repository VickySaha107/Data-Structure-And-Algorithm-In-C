//
//  main.c
//  Exponential
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//
#include <stdio.h>
int pow1(int m,int n){
    if(n==0)
        return 1;
    return pow1(m,n-1)*m;
}
int pow2(int m,int n){
    if(n==0)
        return 1;
    if (n%2==0)
        return pow2(m*m, n/2);
        return m*pow2(m*m, (n-1)/2);
}
int main(int argc, const char * argv[]) {
    // insert code here...
  int r=  pow1(2,5);
    printf("%d ",r);
    return 0;
}

