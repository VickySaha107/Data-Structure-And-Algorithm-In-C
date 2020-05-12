//
//  main.c
//  Toeplitz Matrix
//
//  Created by Bikramjit Saha on 09/05/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//
//row=i,col=j,dim=n,ele=x;
#include<stdio.h>
#include<stdlib.h>
struct matrix
{
int *A;
int n;
};
void set(struct matrix *m,int i,int j,int x)
{
if(i<=j)
m->A[j-i]=x;
if(i>j)
m->A[m->n+i-j-1]=x;
}
int get(struct matrix m,int i,int j)
{
if(i<=j)
return(m.A[j-1]);
if(i>j)
return(m.A[m.n+i-j-1]);
else
return 0;
}
void display(struct matrix m)
{
int i,j;
for(i=1;i<=m.n;i++)
{
for(j=1;j<=m.n;j++)
{
if(i<=j)
printf("%d ",m.A[j-i]);
if(i>j)
printf("%d ",m.A[m.n+i-j-1]);
}
printf("\n");
}
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct matrix m;
    m.n=5;
    m.A=(int*)malloc(2*m.n-1*sizeof(int));
    set(&m, 1, 1, 2);set(&m, 1, 2, 3);set(&m, 1, 3, 4);set(&m, 1, 4, 5);set(&m, 1, 5, 6);set(&m, 2, 1, 7);set(&m, 3, 1, 8);set(&m, 4, 1, 9);set(&m, 5, 1, 1);
    printf("%d\n",get(m, 1, 4));
    display(m);
    return 0;
}
