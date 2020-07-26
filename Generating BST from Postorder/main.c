//
//  main.c
//  Generating BST from Postorder
//
//  Created by Bikramjit Saha on 02/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;
void createpre(struct Node*p,int pre[],int size){
    struct Stack stk;Create(&stk,50);
    struct Node*t,*q;
    int i=0;
    root=(struct Node *)malloc(sizeof(struct Node ));
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while(i<size){
        if(pre[i]<p->data){
            t=(struct Node *)malloc(sizeof(struct Node ));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            Push(&stk,p);
            p=t;
        }
        else if((pre[i]>p->data&&pre[i]<stackTop(stk)->data)){
            t=(struct Node *)malloc(sizeof(struct Node ));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            p=t;
        }
        else{
            p=Pop(&stk);
            if (isEmpty(stk))
            {
                q=(struct Node *)malloc(sizeof(struct Node ));
                q->data=INT32_MAX;
                q->rchild=q->lchild=NULL;
                Push(&stk,q);
            }
        }
    }
}
void Inorder(struct Node*p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
    printf("");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int pre[]={30,20,10,15,25,40,50,45};
    createpre(root, pre, 8);
    Inorder(root);
    printf("\n");
    return 0;
}
