#include<iostream>
#include<string>
using namespace std;
#define MaxSize 10

typedef struct queue{
    int data[MaxSize];
    int front,rear;
}Queue;

void InitQueue(Queue *&q){
    q=new Queue;
    q->front=q->rear=-1;
}

bool EnQueue(Queue *&q,int a){
    if(q->front>MaxSize-1)
        return false;
    q->front++;
    q->data[q->front]=a;
    return true;
}

int DeQueue(Queue *&q){
    int a;
    a=q->data[q->rear+1];
    q->rear++;
    return a;
}

void DestroyQueue(Queue *&q){
    free(q);
}

bool EmptyQueue(Queue *q){
    return q->rear==q->front;
}

int main()
{
    Queue *q;
    InitQueue(q);
    for(int i=0;i<=20;i++){
        if(i%2==0)
            EnQueue(q,i);
    }
    while(!EmptyQueue(q))
    {
        cout<<DeQueue(q)<<" ";
    }
    DestroyQueue(q);
    return 0;
}
