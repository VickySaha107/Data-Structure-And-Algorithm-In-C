//
//  main.c
//  2D_Array
//
//  Created by Bikramjit Saha on 22/04/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int a[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    int b1[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    int *b[3];
    b[0]=(int*)malloc(4*sizeof(int));
    b[1]=(int*)malloc(4*sizeof(int));
    b[2]=(int*)malloc(4*sizeof(int));
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ",b1[i][j]);
        }
        printf("\n");
    }
    int c1[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};
    int**c;/*double pointer */
    c=(int**)malloc(3*sizeof(int*));
    c[0]=(int*)malloc(4*sizeof(int));
    c[1]=(int*)malloc(4*sizeof(int));
    c[2]=(int*)malloc(4*sizeof(int));
    for (int i=0;i<3;i++){
    for(int j=0;j<4;j++){
        printf("%d ",c1[i][j]);
      }
        printf("\n");
   }
    return 0;
}
