//
//  main.c
//  Combination
//
//  Created by Bikramjit Saha on 20/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
int factI(int n){
    int s=1;
    for (int i=1;i<=n; i++) {
        s=s*i;
    }
    return s;
}
int factR(int n){
    if(n==0)
        return 1;
    else
        return factR(n-1)*n;
}
int nCrI(int n,int r){
    if(r==0||r==n)
        return 1;
    else
       return nCrI(n-1, r-1)+nCrI(n-1, r);
}
int nCrR(int n,int r)
{
    int t1,t2,t3;
    t1=factR(n);
    t2=factR(r);
    t3=factR(n-r);
    return t1/(t2*t3);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d ",factI(6));
    return 0;
}
