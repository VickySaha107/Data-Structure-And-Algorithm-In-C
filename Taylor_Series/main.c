//
//  main.c
//  Taylor_Series
//
//  Created by Bikramjit Saha on 20/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//
#include <stdio.h>
double e1(double x,double n){
    static double sum=1;
    if(n==0)
        return sum;
    for (;n>0; n--) {
        sum=1+(x/n)*sum;
    }
    return sum;
}
double e2(double x,double n){
    static double sum=1;
    if (n==0)
        return sum;
        sum=1+(x/n)*sum;
    return e2(x,n-1);
}
double e(int x,int n){
    static double pow=1,fact=1;
    double retf;

    if (n==0)
        return 1;
    else
       retf= e(x,n-1);
        pow=pow*x;
        fact=fact*n;
        return retf+(pow/fact);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%lf \n" ,e1(1,10));
    printf("%lf \n" ,e2(2,12));
    printf("%lf \n" ,e(3,11));
    return 0;
}
