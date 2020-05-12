//
//  main.c
//  Tri-Diagonal Matrix
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
void Set(struct Matrix *TD,int row,int col,int ele){
    if(row-col==-1){
        TD->A[row-1]=ele;
    }
    else if (row-col==0){
        TD->A[TD->dim-1+(row-1)]=ele;
    }else if(row-col==1){
        TD->A[TD->dim-1+TD->dim+(row-2)]=ele;
    }
}
  int Get(struct Matrix TD,int row,int col){
      if(row-col==-1){
        return TD.A[row-1];
      }
    else if (row-col==0){
        return TD.A[TD.dim-1+(row-1)];
    }else if(row-col==-1){
        return TD.A[TD.dim-1+TD.dim+(row-2)];
    }else
        return 0;
}
void DisplayDM(struct Matrix TD){
   int row,col;
   for(row=1;row<=TD.dim;row++){
       for(col=1;col<=TD.dim;col++){
           if(row-col==-1)
               printf("%d ",TD.A[row-1]);
           else if(row-col==0){
               printf("%d ",TD.A[TD.dim-1+(row-1)]);
           }
           else if(row-col==1){
               printf("%d ",TD.A[TD.dim-1+TD.dim+(row-2)]);
           }else
               printf("0 ");
       }
       printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Matrix TD;
    TD.dim=5;
    TD.A=(int*)malloc(3*TD.dim-2*sizeof(int));/*DIMENSION FOR NON ZERO ELEMENT*/
    Set(&TD,1,1,9);Set(&TD,1,2,5);Set(&TD,2,1,2);Set(&TD,2,2,6);Set(&TD,2,3,2);Set(&TD,3,2,9);Set(&TD,3,3,1);Set(&TD,3,4,7);Set(&TD,4,3,3);Set(&TD,4,4,7);Set(&TD,4,5,5);Set(&TD,5,4,8);Set(&TD,5,5,1);
    printf("%d\n",Get(TD,2,2));
    DisplayDM(TD);
    return 0;
}

