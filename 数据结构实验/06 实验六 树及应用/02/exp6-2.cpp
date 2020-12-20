#include <stdio.h>
#include <malloc.h>
#define MaxSons 10
#define MaxSize 100
typedef struct node
{
    char data;                  //�ڵ��ֵ
    struct node *sons[MaxSons]; //ָ���ӽڵ�
} TSonNode;                     //�������洢�ṹ����

TSonNode *CreateTree(char *str) //��str�����������洢�ṹ
{
    struct
    {
        TSonNode *nodep; //�ڵ�ָ��
        int num;         //���Ӹ���
    } St[MaxSize];       //����˳��ջ
    int top = -1;        //ջ��ָ��
    int i = 0, j;
    char ch = str[i];
    TSonNode *t = NULL, *p;
    while (ch != '\0')
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top].nodep = p;
            St[top].num = 0; //��ǰ�ڵ�*p��ջ
            break;
        case ')':
            top--;
            break; //��ջ
        case ',':
            St[top].num++;
            break; //ջ���ڵ�����һ������
        default:
            p = (TSonNode *)malloc(sizeof(TSonNode));
            p->data = ch;                 //����һ���ڵ�p���ch
            for (j = 0; j < MaxSons; j++) //���к���ָ����ΪNULL
                p->sons[j] = NULL;
            if (t == NULL) //ԭΪ����
                t = p;
            else //������Ϊջ���ڵ��һ������
                St[top].nodep->sons[St[top].num] = p;
            break;
        }
        i++;
        ch = str[i];
    }
    return t;
}

void DispTree(TSonNode *t) //����������洢�ṹ
{
    int i;
    if (t != NULL)
    {
        printf("%c", t->data);
        if (t->sons[0] != NULL) //t�ڵ�������һ������
        {
            printf("("); //���һ��������
            for (i = 0; i < MaxSons; i++)
            {
                DispTree(t->sons[i]);
                if (t->sons[i + 1] != NULL) //�������һ������
                    printf(",");            //���һ��','
                else                        //���û����һ������
                    break;                  //�˳�ѭ��
            }
            printf(")"); //���һ��������
        }
    }
}

void DestroyTree(TSonNode *&t) //������t
{
    int i;
    if (t != NULL)
    {
        for (i = 0; i < MaxSons; i++)
        {
            if (t->sons[i] != NULL)      //������
                DestroyTree(t->sons[i]); //���ٸ�����
            else                         //��û������
                break;                   //�˳�ѭ��
        }
        free(t); //�ͷŸ��ڵ�
    }
}

int TreeHeight(TSonNode *t) //����t�߶�
{
    TSonNode *p;
    int i, h, maxh = 0;
    if (t == NULL)
        return 0; //�������ظ߶�0
    else          //����ǿ���
    {
        for (i = 0; i < MaxSons; i++)
        {
            p = t->sons[i]; //pָ��t�ĵ�i-1�����ӽڵ�
            if (p != NULL)  //�����ڵ�i-1������
            {
                h = TreeHeight(p); //�����Ӧ�����ĸ߶�
                if (maxh < h)
                    maxh = h; //���������������߶�
            }
        }
        return (maxh + 1); //����maxh+1
    }
}
int main()
{
    TSonNode *t;
    printf("�������źͶ�����ʽ��ʾ��:");
    char c[MaxSize];
    scanf("%s", c);
    t = CreateTree(c);
    printf("T:");
    DispTree(t);
    printf("\n��T�ĸ߶�:%d\n", TreeHeight(t));
    DestroyTree(t);
    return 0;
}
