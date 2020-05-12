//
//  main.c
//  Tower_Of_Hanoi
//
//  Created by Bikramjit Saha on 21/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
void Toh(int n,int a,int b,int c){
    if(n>0){
        Toh(n-1,a,c,b);
    printf(" (from %d to %d) ",a,c);
    Toh(n-1,b,a,c);
}
}
int main(int argc, const char * argv[]) {
    // insert code here...
  Toh(3,1,2,3);
    return 0;
}
