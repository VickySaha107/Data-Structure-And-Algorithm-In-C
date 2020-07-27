//
//  main.c
//  Stack Using Array
//
//  Created by Bikramjit Saha on 05/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int size;
    int top;
    int *s;
};
void create(struct Stack *stk){
    
    printf("Enter the size:\n");
    
    scanf("%d",&stk->size);
    
    stk->top=-1;
    
    stk->s=(int*)malloc(stk->size*sizeof(int));
}
void Display(struct Stack stk){
    int i;
    for (i=stk.top; i>=0; i--) {
        printf("%d ",stk.s[i]);
    }
    printf("\n");
}
void Push(struct Stack *stk,int val){
//    before inserting check stack is full or not
    if (stk->top==stk->size-1) {
        printf("Stack Overflow\n");
    }else{
        stk->top++;
        stk->s[stk->top]=val;
    }
}
int Pop(struct Stack *stk){
    int Store=-1;
    if (stk->top==-1) {
        printf("Stack is Empty\n");
    }else{
        Store=stk->s[stk->top--];
    }
    return Store;
}
int Peek(struct Stack stk,int pos){
    int x=-1;
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
int StackTop(struct Stack stk){
    if (!isEmpty(stk)) {
        return stk.s[stk.top];
    }else{
        return -1;
    }
}
int isFull(struct Stack stk){
    if (stk.top==stk.size-1) {
        return 1;
    }else{
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Stack stk;
    create(&stk);
    Push(&stk,20);
    Push(&stk,30);
    Push(&stk,40);
    Push(&stk,50);
    Push(&stk,60);
    Push(&stk,100);
    Display(stk);
    if (isEmpty(stk)) {
        printf("Yes,Stack is Empty\n");
    }else{
        printf("No,Stack is Not Empty\n");
    }
    if (StackTop(stk)) {
           printf("%d\n",stk.s[stk.top]);
       }
    if (isFull(stk)) {
        printf("Stack is Full\n");
    }else{
        printf("Stack is Not Full\n");
    }
    Pop(&stk);
    Display(stk);
    return 0;
}
