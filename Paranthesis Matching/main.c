//
//  main.c
//  Paranthesis Matching
//
//  Created by Bikramjit Saha on 06/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node * next;
}*top=NULL;

void PUSH(char x)
{

   struct Node *t;

   t=(struct Node *)malloc(sizeof (struct Node));

if (t==NULL)

   printf("stack is full\n");

else

{
   t->data=x;

   t->next=top;

   top=t;

}

}

  char POP()

{

    char x =-1;

       if (top==NULL)

          printf("stack is empty and nothing can be poped\n");
   else

{
    struct Node *p;

     p=top;

     top=top->next;

     x=p->data;

     free(p);
  }
   return x;
}

int isBalance(char *exp)

{

    int i;

    char q;

    for (i=0;exp[i]!='\0';i++)

      {

          if (exp[i]=='{'|| exp[i]=='(' || exp[i]=='[' )

            PUSH(exp[i]);

        else if (exp[i]=='}')

        {

            if (top==NULL)

              return 0;

            else

              q=POP();

          if (q!='{')

            return 0;//match not found

        }

       else if (exp[i]==')')

        {

            if (top==NULL)

              return 0;

            else

              q=POP();

          if (q!='(')

            return 0;//match not found

        }

      else if (exp[i]==']')

        {

            if (top==NULL)

              return 0;

            else

              q=POP();

          if (q!='[')

            return 0;//match not found

        }

      }

        if (top==NULL)

           return 1;

         else

           return 0;

}


int main ()

{

char *exp = "{([a+b] * [c+d])/e}";

    if (isBalance(exp)) {
        printf("Balanced\n");
    }else{
        printf("Not Balanced\n");
    }

return 0;

}
