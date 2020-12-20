//exp4-3.cpp
#include "sqqueue.cpp"
int main()
{
    ElemType e;
    SqQueue *q;
    printf("环形队列基本运算如下:\n");
    printf("  (1)初始化队列q\n");
    InitQueue(q);
    printf("  (2)依次进队列元素a,b,c\n");
    enQueue(q, 'a');
    enQueue(q, 'b');
    enQueue(q, 'c');
    printf("  (3)队列为%s\n", (QueueEmpty(q) ? "空" : "非空"));
    if (deQueue(q, e) == 0)
        printf("队空,不能出队\n");
    else
        printf("  (4)出队一个元素%c\n", e);
    printf("  (5)依次进队列元素d,e,f\n");
    enQueue(q, 'd');
    enQueue(q, 'e');
    enQueue(q, 'f');
    printf("  (6)出队列序列:");
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        printf("%c ", e);
    }
    printf("\n");
    printf("  (7)释放队列\n");
    DestroyQueue(q);
    return 0;
}
