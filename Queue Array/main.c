//
//  main.c
//  Queue Array
//
//  Created by Bikramjit Saha on 16/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};
void create (struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q =(int*)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue*q,int val){
    if (q->rear==q->size-1) {
        printf("Queue is Full\n");
    }else{
        q->rear++;
        q->Q[q->rear]=val;
    }
}
int dequeue(struct Queue*q){
    int str=-1;
    if (q->front==q->rear) {
        printf("Queue is Empty\n");
    }else{
        q->front++;
        str=q->Q[q->front];
    }
    return str;
}
void Display(struct Queue q){
    int i;
    for (i=q.front+1; i<=q.rear; i++) {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Queue q;
    create(&q, 5);
    
    enqueue(&q, 10);
    enqueue(&q, 13);
    enqueue(&q, 16);
    enqueue(&q, 6);
    enqueue(&q, 9);
    
    Display(q);
    
    printf("%d \n",dequeue(&q));
    printf("%d \n",dequeue(&q));
    return 0;
}
