//
//  main.c
//  AVL Rotation on BST
//
//  Created by Bikramjit Saha on 04/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node*lchild;
    int height;
    int data;
    struct Node*rchild;
}*root=NULL;
int NodeHeight(struct Node*p){
    int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct Node*p){
   int hl,hr;
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl-hr;
}
struct Node*LLrotation(struct Node*p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
        root=pl;
    return pl;
}
struct Node * LRrotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(root==p)
        root=plr;
    return plr;
}
struct Node*RRrotation(struct Node*p){
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;
    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
    root=pr;
    return pr;
}
struct Node*RLrotation(struct Node*p){
    struct Node *pr=p->rchild;
    struct Node *prl=pr->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->rchild=pr;
    prl->lchild=p;
    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);
    prl->height=NodeHeight(prl);
     
    if(root==p)
    root=prl;
    return p;
}
void Inorder(struct Node*p){
    if (p) {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
    printf("");
}
struct Node* RInsert(struct Node*p,int key){
    struct Node*t=NULL;
    if (!p) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->height=1;// Node height is initially 1 i.e one node is present
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if (key<p->data) {
        p->lchild=RInsert(p->lchild, key);
    }else if(key>p->data){
        p->rchild=RInsert(p->rchild, key);
    }
    // which ever subtree is greater it will take that height
    p->height=NodeHeight(p);
    // check the balance factor and decide which rotation to implement
    if (BalanceFactor(p)==2&&BalanceFactor(p->lchild)==1) {
        LLrotation(p);
        
    } else if (BalanceFactor(p)==2&&BalanceFactor(p->lchild)==-1){
        LRrotation(p);
        
    } else if (BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==-1){
        RRrotation(p);
        
    }else if(BalanceFactor(p)==-2&&BalanceFactor(p->rchild)==1){
        RLrotation(p);
        
    }
    return p;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    root=RInsert(root, 50);
    RInsert(root, 20);
    RInsert(root, 30);
    Inorder(root);
    printf("\n");
    return 0;
}
