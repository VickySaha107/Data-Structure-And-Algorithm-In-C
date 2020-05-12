//
//  main.c
//  Increase_Array-Size
//
//  Created by Bikramjit Saha on 22/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int *p=(int*)malloc(5*sizeof(int));
     p[0]=6;p[1]=5;p[2]=4;p[3]=2;p[4]=1;
    int *q=(int*)malloc(10*sizeof(int));
    for(int i=0;i<5;i++)
        q[i]=p[i];
    free (p);
    p=q;
    // insert code here...
    for(int i=0;i<5;i++)
    printf("%d " ,q[i]);
    printf("\n");
    q=NULL;
    return 0;
}
