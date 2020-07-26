//
//  main.c
//  Nested_Recursion
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
int fun(int n){
    if (n>100)
    return n-10;
    else
    return fun(fun(n+11));
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    fun(95);
    printf("%d\n",fun(95));
    return 0;
}
