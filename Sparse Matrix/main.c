//
//  main.c
//  Sparse Matrix
//
//  Created by Bikramjit Saha on 10/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
struct Element{
    int i;
    int j;
    int x;
};
struct Sparse{
    int m;
    int n;
    int nums;
    struct Element *e;
};
void create(struct Sparse *M){
    int i;
    printf("Enter The Dimension:");
    scanf("%d%d",&M->m,&M->n);
    printf("Enter The Non zero Element:");
    scanf("%d",&M->nums);
    M->e=(struct Element*)malloc(M->nums*sizeof(struct Element));
    printf("Enter The Element:\n");
    for(i=0;i<M->nums;i++){
        scanf("%d",&M->e[i].i);
        scanf("%d",&M->e[i].j);
        scanf("%d",&M->e[i].x);
    }
}
void Display(struct Sparse M){
    int i,j,k=0;/*here k means all the val are initially set to 0 in e*/
    for(i=1;i<=M.m;i++){
        for(j=1;j<=M.n;j++){
            if(i==M.e[k].i&&j==M.e[k].j)
                printf("%d ",M.e[k++].x);
            else
            printf("0 ");
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Sparse M;
    create(&M);
    Display(M);
    return 0;
}
