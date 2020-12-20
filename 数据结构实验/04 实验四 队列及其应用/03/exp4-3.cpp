#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(SqQueue *&q)
{
    free(q);
}

//判断队是否为空
bool QueueEmpty(SqQueue *q)
{
    return (q->front == q->rear);
}

//入队
bool enQueue(SqQueue *&q, ElemType e)
{
    if (q->rear == MaxSize - 1)
        return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

//出队
bool deQueue(SqQueue *&q, ElemType &e)
{
    if (q->front == q->rear)
        return false;
    q->front++;
    e = q->data[q->front];
    return true;
}

//主函数
int main()
{
    SqQueue *q;
    int a, count = 1;
    InitQueue(q);
    for (int i = 1; i <= 10; i++)
        enQueue(q, i);
    printf("出队的序列为:\n");
    while (!QueueEmpty(q))
    {
        deQueue(q, a);
        if (count % 2 != 0)
            enQueue(q, a);
        else
            printf("%d ", a);
        count++;
    }
    printf("\n");
    DestroyQueue(q);
    return 0;
}
