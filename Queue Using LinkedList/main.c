//
//  main.c
//  Queue Using LinkedList
//
//  Created by Bikramjit Saha on 17/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*front=NULL,*rear=NULL;
void enqueue(int val){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    if (t==NULL) {
        //Heap Memory is Full
        printf("Queue is Full\n");
    }else{
        t->data=val;
        t->next=NULL;
        if (front==NULL) {
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int str=-1;
    struct Node*p;
    if (front==NULL) {
        printf("Queue is Empty\n");
    }
    else{
        p=front;
        str=front->data;
        front=front->next;
        free(p);
    }
    return str;
}

void Display( struct Node*p){
    while (p) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...

     enqueue(10);

     enqueue(20);

     enqueue(30);

     enqueue(40);

     enqueue(50);

     Display(front);

     printf("%d \n",dequeue());
    Display(front);
    printf("%d \n",dequeue());
    Display(front);

     return 0;
}

