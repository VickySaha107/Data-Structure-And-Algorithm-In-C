//
//  main.c
//  Dequeue Using Array
//
//  Created by Bikramjit Saha on 18/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int*)malloc(q->size*sizeof(int));
}
void InsertUsingRear(struct Queue*q,int val){
    if (q->rear==q->size+1) {
        printf("Queue is Full \n");
    }
    else{
        q->Q[++q->rear]=val;
    }
}
void InsertUsingFront(struct Queue*q,int val){
    if (q->front==-1&&q->front<q->rear) {
        printf("Warning Queue is Full \n");
    }
    else{
        q->Q[q->front--]=val;
    }
}
int DeleteUsingFront(struct Queue*q){
    int str=-1;
    if (q->front==q->rear) {
        printf("Queue is Empty\n");
    }else{
        str=q->Q[++q->front];
    }
    return str;
}
int DeleteUsingRear(struct Queue*q){
    int str=-1;
    if (q->front==q->rear) {
        printf("Warning Queue is Empty\n");
    }else{
        str=q->Q[q->rear--];
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

    create(&q,6);

    InsertUsingRear(&q,10);

    InsertUsingRear(&q,20);

    InsertUsingRear(&q,30);

    InsertUsingRear(&q,40);

    InsertUsingRear(&q,50);

    InsertUsingRear(&q,60);


    Display(q);

    printf("FIFO delete:%d\n",DeleteUsingFront(&q));
    printf("LIFO delete:%d\n",DeleteUsingRear(&q));
    Display(q);
     
    InsertUsingFront(&q, 70);
    InsertUsingRear(&q, 80);
    InsertUsingRear(&q, 90);
    Display(q);
// Dynamically Size gets increased in Heap
    
    return 0;
}
