//
//  main.c
//  Static_Global
//
//  Created by Bikramjit Saha on 19/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
//same goes with global variable
int z=0;
int fun(int n)
{
    
    if(n>0){
        z++;
        return fun(n-1)+z;
    }
    return 0;
    
}
int main() {
    // insert code here...
    int x=5;
    printf("%d\n",fun(x));
  printf("%d\n",fun(x));
//    sec print statement is 50 because gloabal variable is incremenented from 5 to 10
    return 0;
}
