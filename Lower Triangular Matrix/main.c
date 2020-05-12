//
//  main.c
//  Lower Triangular Matrix
//
//  Created by Bikramjit Saha on 08/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Matrix{
    int *A;
    int dim;
};
void SetRM(struct Matrix *LTM,int row,int col,int ele){
    if(row>=col){
        LTM->A[row*(row-1)/2+col-1]=ele;
    }
}
int GetRM(struct Matrix LTM,int row,int col){
    if(row>=col)
        return LTM.A[row*(row-1)/2+col-1];
    else
        return 0;
}
void SetCM(struct Matrix *LTM,int row,int col,int ele){
    if(row>=col){
        LTM->A[LTM->dim*(col-1)-(col-2)*(col-1)/2+row-col]=ele;
    }
}
int GetCM(struct Matrix LTM,int row,int col){
    if(row>=col)
        return LTM.A[LTM.dim*(col-1)-(col-2)*(col-1)/2+row-col];
    else
        return 0;
}
void DisplayRM(struct Matrix LTM){
   int row,col;
   for(row=1;row<=LTM.dim;row++){
       for(col=1;col<=LTM.dim;col++){
           if(row>=col)
               printf("%d ",LTM.A[row*(row-1)/2+col-1]);
           else
               printf("0 ");
       }
       printf("\n");
    }
}
void DisplayCM(struct Matrix LTM){
    int row,col;
    for(row=1;row<=LTM.dim;row++){
        for(col=1;col<=LTM.dim;col++){
            if(row>=col)
                printf("%d ",LTM.A[LTM.dim*(col-1)-(col-2)*(col-1)/2+row-col]);
            else
                printf("0 ");
        }
        printf("\n");
     }
 }
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Matrix LTM;
    LTM.A=(int*)malloc(LTM.dim*(LTM.dim+1)/2*sizeof(int));/*DIMENSION FOR NON ZERO ELEMENT*/
    LTM.dim=4;
//    SetRM(&LTM,1,1,3);SetRM(&LTM,2,1,7);SetRM(&LTM,2,2,4);SetRM(&LTM,3,1,9);SetRM(&LTM,3,2,6);SetRM(&LTM,3,3,3);SetRM(&LTM,4,1,7);SetRM(&LTM,4,2,4);SetRM(&LTM,4,3,9);SetRM(&LTM,4,4,5);
    SetCM(&LTM,1,1,3);SetCM(&LTM,2,1,7);SetCM(&LTM,2,2,4);SetCM(&LTM,3,1,9);SetCM(&LTM,3,2,6);SetCM(&LTM,3,3,3);SetCM(&LTM,4,1,7);SetCM(&LTM,4,2,4);SetCM(&LTM,4,3,9);SetCM(&LTM,4,4,5);
//    printf("%d\n",GetRM(LTM, 2, 2));
    printf("%d\n",GetCM(LTM, 2, 2));
//    DisplayRM(LTM);
    DisplayCM(LTM);
    return 0;
}
 
