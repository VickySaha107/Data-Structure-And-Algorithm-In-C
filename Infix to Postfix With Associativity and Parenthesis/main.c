//
//  main.c
//  Infix to Postfix With Associativity and Parenthesis
//
//  Created by Bikramjit Saha on 07/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
struct stack
{
int size;
int top;
char *s;
};
int isoperand(char x)
{
if(x=='+' ||x=='-'||x=='*' ||x=='/' ||x=='^')
{
return 0;
}
else
return 1;
}
void push(struct stack *st,char x)
{
if(st->top==st->size-1)
{
printf("stack overflow.");
}
else
{
st->top++;
st->s[st->top]=x;
}
}
char pop(struct stack *st)
{
if(st->top!=-1)
return st->s[st->top--];
else
printf("stack empty.");
return 0;
}
int inpre(char x)
{
if(x=='+'|| x=='-')
return 2;
else if(x=='*'|| x=='/')
return 4;
else if(x=='^')
return 5;
else if(x=='(')
return 0;
else return -1;
}
int outpre(char x)
{
if(x=='+'|| x=='-')
return 1;
else if(x=='*'|| x=='/')
return 3;
else if(x=='^')
return 6;
else if(x=='(')
return 7;
else
return 0;
}
char * convert(char *infix)
{
  struct stack st;
  st.s=(char *)malloc(strlen(infix)*sizeof(char));
  st.top=-1;
  char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
  int i=0,j=0;
    while(infix[i]!='\0')
{
   if(isoperand(infix[i]))
   {
     postfix[j++]=infix[i++];
   }
  else
  {
    if(outpre(infix[i])>inpre(st.s[st.top]))
    {
      push(&st,infix[i++]);
    }
     else if(infix[i]==')')
     {
      while(st.top!=-1)
      {
        if(inpre(st.s[st.top])==0)
          pop(&st);
       else
       {
         postfix[j++]=pop(&st);
       }
      }
   i++;
     }
     else if(outpre(infix[i])<inpre(st.s[st.top]))
     {
     postfix[j++]=pop(&st);
     }
  }
}
while(st.top!=0)
{
postfix[j++]=pop(&st);
}
postfix[j]='\0';
return postfix;
}
int main()
{
char *postfix;
char *infix="((a+b)*c)-d^e^f";
postfix=convert(infix);
printf("%s\n",postfix);
return 0;
}
