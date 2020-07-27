//
//  main.c
//  Polynomial Reoresentation Using LinkedList
//
//  Created by Bikramjit Saha on 04/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node{
    int coeff;
    int exp;
    struct Node*next;
}*poly=NULL;
void create(){
struct Node *t,*last=NULL;
int num,i;
printf("Enter number of terms");
scanf("%d",&num);
printf("Enter each term with coeff and exp\n");
for(i=0;i<num;i++)
{
t=(struct Node *)malloc(sizeof(struct Node));
scanf("%d%d",&t->coeff,&t->exp);
t->next=NULL;
if(poly==NULL)
{
poly=last=t;
}
else
{
last->next=t;
last=t;
}
}
}
void Display(struct Node*p){
    while (p) {
        printf("%dx%d + ",p->coeff,p->exp);
        p=p->next;
    }
    printf("\n");
}
long Evaluate(struct Node*p,int x){
    long Sum=0;
    while (p) {
        Sum+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return Sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    create();
    Display(poly);
    printf("%ld\n",Evaluate(poly, 1));
    return 0;
}
