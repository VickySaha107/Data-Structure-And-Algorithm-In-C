//
//  Stack.h
//  CreateTree
//
//  Created by Bikramjit Saha on 28/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
struct Stack{
    int size;
    int top;
    struct node**s;
};
void Create(struct Stack *stk,int size){
    
   
    stk->size=size;
    stk->top=-1;
    
    stk->s=(struct node **)malloc(stk->size*sizeof(struct node *));
}
void Push(struct Stack *stk,struct node *val){
//    before inserting check stack is full or not
    if (stk->top==stk->size-1) {
        printf("Stack Overflow\n");
    }else{
        stk->top++;
        stk->s[stk->top]=val;
    }
}
struct node *Pop(struct Stack *stk){
    struct node *Store=NULL;
    if (stk->top==-1) {
        printf("Stack is Empty\n");
    }else{
        Store=stk->s[stk->top--];
    }
    return Store;
}
struct node * Peek(struct Stack stk,int pos){
    struct node * x=NULL;
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
struct node *stackTop(struct Stack stk)
{
 if(!isEmpty(stk))
      return stk.s[stk.top];
 return NULL;
}

#endif /* Stack_h */
