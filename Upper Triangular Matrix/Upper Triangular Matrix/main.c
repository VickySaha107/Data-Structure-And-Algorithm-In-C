//
//  main.c
//  Upper Triangular Matrix
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
//void SetRM(struct Matrix *UTM,int row,int col,int ele){
//    if(row<=col){
//        UTM->A[UTM->dim*(row-1)-((row-2)*(row-1)/2)+col-row]=ele;
//    }
//}
//int GetRM(struct Matrix UTM,int row,int col){
//    if(row<=col)
//        return UTM.A[UTM.dim*(row-1)-((row-2)*(row-1)/2)+col-row];
//    else
//        return 0;
//}
void SetCM(struct Matrix *UTM,int row,int col,int ele){
    if(row<=col){
        UTM->A[col*(col-1)/2+row-1]=ele;
    }
}
int GetCM(struct Matrix UTM,int row,int col){
    if(row<=col)
        return UTM.A[col*(col-1)/2+row-1];
    else
        return 0;
}
//void DisplayRM(struct Matrix UTM){
//   int row,col;
//   for(row=1;row<=UTM.dim;row++){
//       for(col=1;col<=UTM.dim;col++){
//           if(row<=col)
//               printf("%d ",UTM.A[UTM.dim*(row-1)-((row-2)*(row-1)/2)+col-row]);
//           else
//               printf("0 ");
//       }
//       printf("\n");
//    }
//}
void DisplayCM(struct Matrix UTM){
    int row,col;
    for(row=1;row<=UTM.dim;row++){
        for(col=1;col<=UTM.dim;col++){
            if(row<=col)
                printf("%d ",UTM.A[col*(col-1)/2+row-1]);
            else
                printf("0 ");
        }
        printf("\n");
     }
 }
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Matrix UTM;
    UTM.A=(int*)malloc(UTM.dim*(UTM.dim+1)/2*sizeof(int));/*DIMENSION FOR NON ZERO ELEMENT*/
    UTM.dim=4;
//    SetRM(&UTM,1,1,3);SetRM(&UTM,1,2,7);SetRM(&UTM,1,3,4);SetRM(&UTM,1,4,9);SetRM(&UTM,2,2,6);SetRM(&UTM,2,3,3);SetRM(&UTM,2,4,7);SetRM(&UTM,3,3,4);SetRM(&UTM,3,4,9);SetRM(&UTM,4,4,5);
    SetCM(&UTM,1,1,3);SetCM(&UTM,1,2,7);SetCM(&UTM,1,3,4);SetCM(&UTM,1,4,9);SetCM(&UTM,2,2,6);SetCM(&UTM,2,3,3);SetCM(&UTM,2,4,7);SetCM(&UTM,3,3,4);SetCM(&UTM,3,4,9);SetCM(&UTM,4,4,5);
//   printf("%d\n",GetRM(UTM, 2, 4));
    printf("%d\n",GetCM(UTM, 2, 4));
//    DisplayRM(UTM);
     DisplayCM(UTM);
    return 0;
}
 
