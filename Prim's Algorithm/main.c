//
//  main.c
//  Prim's Algorithm
//
//  Created by Bikramjit Saha on 25/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include<stdio.h>

int main(int argc, const char * argv[]){
    // insert code here...

    int I=INT32_MAX;
    int cost[8][8]={
                {I, I, I, I, I, I, I, I},
                {I, I, 25, I, I, I, 5, I},
                {I, 25, I, 12, I, I, I, 10},
                {I, I, 12, I, 8, I, I, I},
                {I, I, I, 8, I, 16, I, 14},
                {I, I, I, I, 16, I, 20, 18},
                {I, 5, I, I, I, 20, I, I},
                {I, I, 10, I, 14, 18, I, I},
    };
    
    
    int near[8]={I, I, I, I, I, I, I, I};
    int t[2][6];
     
    
    int min=I,i,j, k=0,n=7;
    int ver1=0,ver2=0;
 
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                ver1=i;
                ver2=j;
            }
        }
    }
    t[0][0]=ver1;
    t[1][0]=ver2;
    near[ver1]=near[ver2]=0;
 
    for(i=1;i<=n;i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][ver1]<cost[i][ver2])
                near[i]=ver1;
            else
                near[i]=ver2;
        }
    }
    
    for(i=1;i<n-1;i++)
    {
        min=23761;
        for(j=1;j<=n;j++)
        {
           if(cost[j][near[j]]<min && near[j]!=0)
            {
                k=j;
                min = cost[j][near[j]];
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
                near[j]=k;
        }
    }
    for(i=0;i<n-1;i++)
    {
        printf("(%d,%d) ",t[0][i],t[1][i]);
    }
    printf("\n");
    return 0;
}
