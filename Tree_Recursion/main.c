//
//  main.c
//  Tree_Recursion
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void fun(int n)
{
    if (n>0) {
        printf("%d ",n);
        fun(n-1);
        fun(n-1);
    }
}

int main() {
    // insert code here...
    fun(3);
    return 0;
}

