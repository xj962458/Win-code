//exp4-3.cpp
#include "sqqueue.cpp"
int main()
{
    ElemType e;
    SqQueue *q;
    printf("���ζ��л�����������:\n");
    printf("  (1)��ʼ������q\n");
    InitQueue(q);
    printf("  (2)���ν�����Ԫ��a,b,c\n");
    enQueue(q, 'a');
    enQueue(q, 'b');
    enQueue(q, 'c');
    printf("  (3)����Ϊ%s\n", (QueueEmpty(q) ? "��" : "�ǿ�"));
    if (deQueue(q, e) == 0)
        printf("�ӿ�,���ܳ���\n");
    else
        printf("  (4)����һ��Ԫ��%c\n", e);
    printf("  (5)���ν�����Ԫ��d,e,f\n");
    enQueue(q, 'd');
    enQueue(q, 'e');
    enQueue(q, 'f');
    printf("  (6)����������:");
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        printf("%c ", e);
    }
    printf("\n");
    printf("  (7)�ͷŶ���\n");
    DestroyQueue(q);
    return 0;
}
