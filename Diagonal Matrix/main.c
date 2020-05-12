//
//  main.c
//  Diagonal Matrix
//
//  Created by Bikramjit Saha on 08/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Matrix{
    int A[10];
    int dim;
};
void Set(struct Matrix *DM,int row,int col,int ele){
    if(row==col){
        DM->A[row-1]=ele;
    }
}
int Get(struct Matrix DM,int row,int col){
    if(row==col)
        return DM.A[row-1];
    else
        return 0;
}
void Display(struct Matrix DM){
    int row,col;
    for(row=0;row<DM.dim;row++){
        for(col=0;col<DM.dim;col++){
            if(row==col)
                printf("%d ",DM.A[row]);
            else
                printf("0 ");
        }
        printf("\n");
     }
 }
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Matrix DM;
    DM.dim=5;
    Set(&DM,1,1,3);Set(&DM,2,2,7);Set(&DM,3,3,4);Set(&DM,4,4,9);Set(&DM,5,5,6);
    printf("%d\n",Get(DM, 2, 2));
    Display(DM);
    return 0;
}
 
