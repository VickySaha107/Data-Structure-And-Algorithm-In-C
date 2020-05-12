//
//  main.c
//  Indirect_Recursion
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
//declare the second function
void fun2(int n);
void fun1(int n){
    if (n>0) {
        printf("%d ",n);
        fun2(n-1);
    }
}
void fun2(int n){
    if (n>1){
        printf("%d ",n);
        fun1(n/2);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    fun1(20);
    
    return 0;
}
