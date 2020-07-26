//
//  main.c
//  Circular Queue Array
//
//  Created by Bikramjit Saha on 17/06/20.
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
    /* Check Queue is Full Or Not */
    if ((q->rear+1)%q->size==q->front){
        printf("Queue is Full\n");
    }else{
        /* Increment rear Circularly and Insert */
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=val;
    }
}
int dequeue(struct Queue*q){
    int str=-1;
    if (q->front%q->size==q->rear%q->size) {
        printf("Queue is Empty\n");
    }else{
        /* Increment front Circularly and Delete */
        q->front=(q->front+1)%q->size;
        str=q->Q[q->front];
    }
    return str;
}
void Display(struct Queue q){
//    Display Circularly
    int i=(q.front+1)%q.size;
    //index pointer i should point 1 step ahead of front pointer to display all the elements
    do
    {
    printf("%d ",q.Q[i]);
    i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    //Rear should be always back of front pointer
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 11);
    enqueue(&q, 10);
    enqueue(&q, 12);
    enqueue(&q, 5);
    enqueue(&q, 15);
    Display(q);
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    Display(q);
    enqueue(&q, 20);
    enqueue(&q, 22);
    Display(q);
    printf("\n");
    return 0;
}
