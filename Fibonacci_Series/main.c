//
//  main.c
//  Fibonacci_Series
//
//  Created by Bikramjit Saha on 20/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
int F[10];
int fibM(int n){
    if(F[n]<=1){
        return n;
    }else{
        if (F[n-1]==-1)
            return fibM(n-1);
        if(F[n-2]==-1)
            return fibM(n-2);
    }
    return F[n-1]+F[n-2];
}
int fibI(int n){
   static int t1=0,t2=1,sum;
    if (n<=1)
        return n;
    else
        for (int i=2;i<=n; i++) {
    sum=t1+t2;
    t1=t2;
    t2=sum;
}
    return sum;
}
int fib(int n)
{
    if (n<=1)
        return n;
    else
        return fib(n-2)+fib(n-1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d ",fibM(5));
    printf("%d ",fibI(5));
    printf("%d ",fib(5));
    return 0;
}
