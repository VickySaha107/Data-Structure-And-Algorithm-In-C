//
//  main.c
//  Array_with_Pointer
//
//  Created by Bikramjit Saha on 22/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[5]={3,4,5,6,7};
    for (int i=0;i<5; i++)
        printf("%d ",A[i]);
    printf("\n");
    int *p;
    p=(int*)malloc(5*sizeof(int));
    p[0]=1;
    p[1]=9;
    p[2]=3;
    p[3]=6;
    p[4]=5;
    for (int i=0;i<5; i++)
    printf("%d ",p[i]);
    printf("\n");
    return 0;
}
    
