//
//  stack.h
//  Generating BST from Postorder
//
//  Created by Bikramjit Saha on 02/07/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#ifndef stack_h
#define stack_h
struct Stack{
    int size;
    int top;
    struct Node**s;
};
void Create(struct Stack *stk,int size){
    
   
    stk->size=size;
    stk->top=-1;
    
    stk->s=(struct Node **)malloc(stk->size*sizeof(struct Node *));
}
void Push(struct Stack *stk,struct Node *val){
//    before inserting check stack is full or not
    if (stk->top==stk->size-1) {
        printf("Stack Overflow\n");
    }else{
        stk->top++;
        stk->s[stk->top]=val;
    }
}
struct Node *Pop(struct Stack *stk){
    struct Node *Store=NULL;
    if (stk->top==-1) {
        printf("Stack is Empty\n");
    }else{
        Store=stk->s[stk->top--];
    }
    return Store;
}
struct Node * Peek(struct Stack stk,int pos){
    struct Node * x=NULL;
    if (stk.top-pos+1<0) {
        printf("Position is Invalid\n");
    }else{
        x=stk.s[stk.top-pos+1];
    }
    return x;
}
int isEmpty(struct Stack stk){
    if (stk.top==-1) {
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Stack stk){
    if (stk.top==stk.size-1) {
        return 1;
    }else{
        return 0;
    }
}
struct Node *stackTop(struct Stack stk)
{
 if(!isEmpty(stk))
      return stk.s[stk.top];
 return NULL;
}

#endif /* stack_h */
