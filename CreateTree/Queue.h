//
//  Queue.h
//  CreateTree
//
//  Created by Bikramjit Saha on 27/06/20.
//  Copyright © 2020 Bikramjit Saha. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
struct node
{
struct node *lchild;
int data;
struct node *rchild;
};
 
struct queue
{
int front;
int rear;
int size;
struct node **Q;
};
void create (struct queue *q, int size)
{
q->size = size;
q->front = q->rear = 0;
q->Q = (struct node **)malloc(q->size * sizeof(struct node *));
}
void enqueue(struct queue *q, struct node * x)
{
if((q->rear + 1) % q->size == q->front)
printf("The queues is full\n");
else
{
q->rear = (q->rear + 1)% q->size;
q->Q[q->rear] = x;
}
}
struct node * dequeue(struct queue *q)
{
struct node* x = NULL;
if(q->front == q->rear)
printf("The queue is empty\n");
else
{
q->front = (q->front+1) % q->size;
x = q->Q[q->front];
}
return x;
}
int isempty(struct queue q)
{
return q.front == q.rear;
}
#endif /* Queue_h */
