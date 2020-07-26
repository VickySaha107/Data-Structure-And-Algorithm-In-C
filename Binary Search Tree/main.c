//
//  main.c
//  Binary Search Tree
//
//  Created by Bikramjit Saha on 01/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;
void Insert(struct Node*p,int key){
    struct Node*t,*f=NULL;// f->follow or tail pointer
    if (root==NULL) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        root=t;// root becomes the new node
        return;
    }
    while (p) {
        f=p;
        if (key==p->data) {
            return ;// when key is found don't return anything
        }else if (key<p->data){
            p=p->lchild;
        }else{
            p=p->rchild;
        }
    }
    // when key is not found or p becomes NULL it will come out of the loop,make a new node and link it with follow pointer
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=key;
    t->lchild=t->rchild=NULL;
    if (key<f->data) {
        f->lchild=t;
    }else{
        f->rchild=t;
    }
}
struct Node* RInsert(struct Node*p,int key){
    struct Node*t=NULL;
    if (!p) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if (key<p->data) {
        p->lchild=RInsert(p->lchild, key);
    }else{
        p->rchild=RInsert(p->rchild, key);
    }
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
struct Node* Isearch(struct Node*t,int key){
    while (t) {
        if (key==t->data)
            return t;
        else if (key<t->data)
            t=t->lchild;
    else
        t=t->rchild;
    }
     return NULL;// Key Element not Found
}
int Level(struct Node*p){
    int x,y;
    if (p==NULL) {
        return 0;
    }
    x=Level(p->lchild);
    y=Level(p->rchild);
    return x>y?x+1:y+1;
}
struct Node*Inpre(struct Node*p){
    while (p&&p->rchild) {
        p=p->rchild;
    }
    return p;
}
struct Node*Insucc(struct Node*p){
    while (p&&p->lchild) {
        p=p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node*p,int key){
    struct Node *temp;
 
    if (p == NULL) return p;
 // when root or any node is deleted which is having left and right subtree
    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
 
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
 
    else
    {
 // when leaf node is deleted
        if (p->lchild == NULL)
        {
            temp = p->rchild;
            free(p);
            return temp;
        }
        else if (p->rchild == NULL)
        {
            temp = p->lchild;
            free(p);
            return temp;
        }// check the height of subtree.If left subtree is greater then delete InorderPredecessor also check its rightsubtree.
        
        else if(Level(p->lchild)>Level(p->rchild)){
            
            struct Node*temp=Inpre(p->lchild);// store the Inpre address recursively in pointer temp
            
            p->data=temp->data;// replace p->data with temp->data
            
            p->lchild= Delete(Inpre(p->lchild), temp->data);
            
        }else{
 // this part is executed when both right and left subtree having same level or righsubtree is greater than left subtree
            
         temp = Insucc(p->rchild);
 
           p->data = temp->data;
 
           p->rchild = Delete(Insucc(p->rchild), temp->data);// Insucc-recursive function call upon rightchild
        }
    }
    return p;
 
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Node*temp;
    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 20);
    Insert(root, 8);
    Insert(root, 30);
    Delete(root, 8);
    Inorder(root);
    printf("\n");
    temp=Isearch(root, 30);
    if (temp!=NULL) {
        printf("Element %d is Found\n",temp->data);
    }else
        printf("Element is Not Found\n");
    return 0;
}
