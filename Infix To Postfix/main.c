//
//  main.c
//  Infix To Postfix
//
//  Created by Bikramjit Saha on 07/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    int data;
    struct Node*next;
}*top=NULL;
void Push(char val){
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if (t==NULL) {
        printf("stack is Full\n");
    }else{
        t->data=val;
        t->next=top;
        top=t;
    }
}
int pop(){
    struct Node*t;
    int str=-1;
    if (top==NULL) {
        printf("Stack is Empty\n");
    }else{
        t=top;
        top=top->next;
        str=t->data;
        free(t);
    }
    return str;
}
void Display(){
    struct Node*p=top;
    while (p) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int IsOperand(char val){
        if (val=='+'||val=='-'||val=='*'||val== '/')
         return 0;
         else
         return 1;
}
int precedence(char val){
    if (val=='+'||val=='-') {
        return 1;
    }else if(val=='*'||val=='/'){
        return 2;
    }else{
        return 0;
    }
}

char *InfToPos(char *infix){
    int i = 0,j=0;
    long size=strlen(infix)+1;
    char*postfix;
    postfix=(char*)malloc(size*sizeof(char));
    while (infix[i]!='\0') {
        if (IsOperand(infix[i])) {
            postfix[j++]=infix[i++];
        }if(top==NULL){
            Push(infix[i++]);
        }
        else if(precedence(infix[i])>precedence(top->data)){
            Push(infix[i++]);
        }else{
            postfix[j++]=pop();
        }
    }
    while (top!=NULL) {
       postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}
int Eval(char *postfix){
    int i=0, op1,op2,res = 0;
    for (i=0; postfix[i]!='\0'; i++) {
        if (IsOperand(postfix[i])) {
            Push(postfix[i]-'0');//ASCII CODE 0=48,conversion of char to int in stack
        }else{
            op1=pop();
            op2=pop();
            switch (postfix[i]) {
                case '+':
                    res=op2+op1;
                    Push(res);
                    break;
                case '-':
                    res=op2-op1;
                    Push(res);
                    break;
                case '*':
                    res=op2*op1;
                    Push(res);
                    break;
                case '/':
                    res=op2/op1;
                    Push(res);
                    break;
                default:
                    break;
            }
        }
    }
    return top->data;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char infix[]="3*5+6/2-4";
    char *postfix=InfToPos(infix);
    printf("Converted from Infix to Postfix %s\n",postfix);
    printf("The Result is %d\n",Eval(postfix));
    return 0;
}
