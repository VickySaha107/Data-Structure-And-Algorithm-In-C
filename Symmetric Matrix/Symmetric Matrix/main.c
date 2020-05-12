//
//  main.c
//  Symmetric Matrix
//
//  Created by Bikramjit Saha on 09/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Matrix{
    int *A;
    int dim;
};
//void SetRM(struct Matrix *SM,int row,int col,int ele){
//    int temp;
//    if(row<col){/*swapping index of row with col*/
//        temp=row;
//        row=col;
//        col=temp;
//    }
//    if(row>=col){
//        SM->A[row*(row-1)/2+col-1]=ele;
//    }
//}
//int GetRM(struct Matrix SM,int row,int col){
//    int temp;
//    if(row<col){/*swapping index of row with col*/
//        temp=row;
//        row=col;
//        col=temp;
//    }
//    if(row>=col){
//        return SM.A[row*(row-1)/2+col-1];
//    }
//    else{
//        return 0;
//    }
//}
void SetCM(struct Matrix *SM,int row,int col,int ele){
int temp;
if(row<col){/*swapping index of row with col*/
    temp=row;
    row=col;
    col=temp;
}
    if(row>=col){
        SM->A[SM->dim*(col-1)-(col-2)*(col-1)/2+row-col]=ele;
    }
}
int GetCM(struct Matrix SM,int row,int col){
    int temp;
    if(row<col){/*swapping index of row with col*/
        temp=row;
        row=col;
        col=temp;
    }
    if(row>=col)
        return SM.A[SM.dim*(col-1)-(col-2)*(col-1)/2+row-col];
    else
        return 0;
}
//void DisplayRM(struct Matrix SM){
//   int row,col;
//   for(row=1;row<=SM.dim;row++){
//       for(col=1;col<=SM.dim;col++){
//           if(row>=col)
//               printf("%d ",SM.A[row*(row-1)/2+col-1]);
//           else {
//               printf("%d ",SM.A[col*(col-1)/2+row-1]);
//           }
//       }
//       printf("\n");
//    }
//}
void DisplayCM(struct Matrix SM){
    int row,col;
    for(row=1;row<=SM.dim;row++){
        for(col=1;col<=SM.dim;col++){
            if(row>=col)
                printf("%d ",SM.A[SM.dim*(col-1)-(col-2)*(col-1)/2+row-col]);
            else
                printf("%d ",SM.A[SM.dim*(row-1)-(row-2)*(row-1)/2+col-row]);
        }
        printf("\n");
     }
 }
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Matrix SM;
    SM.A=(int*)malloc(SM.dim*(SM.dim+1)/2*sizeof(int));/*DIMENSION FOR NON ZERO ELEMENT*/
    SM.dim=4;
//    SetRM(&SM,1,1,2);SetRM(&SM,2,1,2);SetRM(&SM,2,2,3);SetRM(&SM,3,1,2);SetRM(&SM,3,2,3);SetRM(&SM,3,3,4);SetRM(&SM,4,1,2);SetRM(&SM,4,2,3);SetRM(&SM,4,3,4);SetRM(&SM,4,4,5);
    SetCM(&SM,1,1,2);SetCM(&SM,2,1,2);SetCM(&SM,2,2,3);SetCM(&SM,3,1,2);SetCM(&SM,3,2,3);SetCM(&SM,3,3,4);SetCM(&SM,4,1,2);SetCM(&SM,4,2,3);SetCM(&SM,4,3,4);SetCM(&SM,4,4,5);
//    printf("%d\n",GetRM(SM, 2, 2));
    printf("%d\n",GetCM(SM, 2, 2));
//     DisplayRM(SM);
    DisplayCM(SM);
    return 0;
}
 
