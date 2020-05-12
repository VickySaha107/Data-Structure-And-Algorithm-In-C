//
//  main.c
//  Factorial!
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
int fact1(int n){
    if (n==0)
        return 1;
    else
        return fact1(n-1)*n;
}
int fact(int n){
    int s=1;
    for (int i=1;i<=n; i++) {
        s=s*i;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    fact1(5);
    printf("%d ",fact1(5));
    return 0;
}
