//
//  main.c
//  CreateTree
//
//  Created by Bikramjit Saha on 27/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"


struct node *root = NULL;
void treecreate()
{
struct node *p, *t;
int val;
struct queue q;
create(&q,20);
printf("Enter the root value: ");
scanf("%d", &val);
root = (struct node *)malloc(sizeof(struct node));
root->data = val;
root->lchild = root->rchild = NULL;
enqueue(&q, root);
while(! isempty(q))
{
p = dequeue(&q);// pointer p will take the address of dequeue element2
printf("Enter the left child of %d: ", p->data);
scanf("%d", &val);
if(val!= -1)
{
t = (struct node *)malloc(sizeof(struct node));
t->data = val;
t->lchild = t->rchild = NULL;
p->lchild = t;
enqueue(&q, t);
}
printf("Enter the right child of %d: ", p->data);
scanf("%d", &val);
if(val != -1)
{
t = (struct node *)malloc(sizeof(struct node));
t->data = val;
t->lchild = t->rchild = NULL;
p->rchild = t;
enqueue(&q, t);
}
}
}
/**
 All the traversals take Time complexity of O(n)
 Total n nodes  and n+1 null pointer are their
 so total n+n+1=2n+1 calls are made .Moreover printing takes constant timeO(1)
 */
void preorder1(struct node *p)
{
if(p)
{
printf("%d ", p->data);
preorder1(p->lchild);
preorder1(p->rchild);
}
}

void Inorder1(struct node *p){
    if(p)
{
Inorder1(p->lchild);
    printf("%d ",p->data);
Inorder1(p->rchild);

}
}

void postorder1(struct node *p){
    if(p)
{
postorder1(p->lchild);
postorder1(p->rchild);
printf("%d ",p->data);
}
}

void IpreOrder(struct node*p){
    struct Stack stk;
    Create(&stk, 100);
    while (p||!isEmpty(stk)) {
        if (p) {
            printf("%d ",p->data);
            Push(&stk, p);
            p=p->lchild;
        }else{
        p=Pop(&stk);
        p=p->rchild;
        }
    }
}

void IInOrder(struct node*p){
    struct Stack stk;
    Create(&stk, 100);
    while (p||!isEmpty(stk)) {
        if (p) {
            Push(&stk, p);
            p=p->lchild;
        }else{
        p=Pop(&stk);
            printf("%d ",p->data);
        p=p->rchild;
        }
    }
}

void Levelorder(struct node*p){
    struct queue q;
    create(&q, 100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while (!isempty(q)) {
        p=dequeue(&q);
        if (p->lchild) {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if (p->rchild) {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

int  countNode(struct node*p){
    if (!p) {
        return 0;
    }
    return countNode(p->lchild)+countNode(p->rchild)+1;
}
int  sumNode(struct node*p){
    if (!p) {
        return 0;
    }
    return sumNode(p->lchild)+sumNode(p->rchild)+p->data;
}

int LevelNode(struct node *p){
    int x,y=0;
    x=countNode(p->lchild);
    y=countNode(p->rchild);
    if(x>y){
       return x+1;
    }else{
       return y+1;
    }
    return 0;
}
int countdeg2(struct node *p){
    int x,y=0;
    x=countNode(p->lchild);
    y=countNode(p->rchild);
    if(p->lchild && p->rchild){
       return x+y+1;
    }else{
       return x+y;
    }
    return 0;
}
int countdeg0(struct node *p){
    int x,y=0;
    x=countNode(p->lchild);
    y=countNode(p->rchild);
    if(!p->lchild && !p->rchild){
       return x+y+1;
    }else{
       return x+y;
    }
    return 0;
}

int countdeg1or2(struct node *p){
    int x,y=0;
    x=countNode(p->lchild);
    y=countNode(p->rchild);
    if(p->lchild||p->rchild){
       return x+y+1;
    }else{
       return x+y;
    }
    return 0;
}
int countdeg1(struct node *p){
    int x,y=0;
    x=countNode(p->lchild);
    y=countNode(p->rchild);
    if(x^y){
       return x+y+1;
    }else{
       return x+y;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    treecreate();
    printf("Sum of node:%d\n",sumNode(root));
    printf("CountNode:%d\n",countNode(root));
    printf("Leaf Nodes:%d\n",countdeg0(root));
    printf("Strict Degree2:%d\n",countdeg2(root));
    printf("Strict Degree1:%d\n",countdeg1(root));
    printf("Degree1or2:%d\n",countdeg1or2(root));
    printf("Total Level are:%d\n",LevelNode(root));
    printf("Level order: ");
    Levelorder(root);
    printf("\nIPreOrder order: ");
    IpreOrder(root);
    printf("\nIInOrder order: ");
    IInOrder(root);
   printf("\n Pre Order: ");
   preorder1(root);
    printf("\n Inorder: ");
    Inorder1(root);
    printf("\n Post Order: ");
    postorder1(root);
    printf("\n");
    return 0;
}

