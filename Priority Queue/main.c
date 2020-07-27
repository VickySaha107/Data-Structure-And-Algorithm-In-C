//
//  main.c
//  Priority Queue
//
//  Created by Bikramjit Saha on 18/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*f1,*r1,*f2,*r2,*f3,*r3=NULL;
void enqueue1(char val){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue1 is Full\n");
    }else{
        t->data=val;
        t->next=NULL;
        if (f1==NULL) {
            f1=r1=t;
        }else{
            r1->next=t;
            r1=t;
        }
    }
}
void enqueue2(char val){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue2 is Full\n");
    }else{
        t->data=val;
        t->next=NULL;
        if (f2==NULL) {
            f2=r2=t;
        }else{
            r2->next=t;
            r2=t;
        }
    }
}
void enqueue3(char val){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue3 is Full\n");
    }else{
        t->data=val;
        t->next=NULL;
        if (f3==NULL) {
            f3=r3=t;
        }else{
            r3->next=t;
            r3=t;
        }
    }
}
void Insert(char val,int prio){
    if (prio==1) {
        enqueue1(val);
    }else if (prio==2){
        enqueue2(val);
    }else{
        enqueue3(val);
    }
    
}
void Display(struct Node *p){
    while (p) {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Insert('A', 1);
    Insert('B', 1);
    Insert('C', 2);
    Insert('D', 3);
    Insert('E', 2);
    Insert('F', 2);
    Insert('G', 1);
    Insert('H', 3);
    Display(f1);
    Display(f2);
    Display(f3);
   
    return 0;
}
