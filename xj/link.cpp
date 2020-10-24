#include <iostream>
using namespace std;

class CList
{
private:
    struct Node
    {
        int nValue;
        Node *pNext;
    };
    Node *m_pHead;
    Node *m_pEnd;
    int m_nSize;

public:
    CList()
    {
        m_pHead = 0;
        m_pEnd = 0;
        m_nSize = 0;
    }
    ~CList()
    {
        Node *pDel = NULL;
        while (m_pHead)
        {
            pDel = m_pHead;
            m_pHead = m_pHead->pNext;
            delete pDel;
            pDel = NULL;
        }
    }

public:
    void Push_Back(int nVal)
    {
        //  ��Ҫһ���ڵ�
        Node *pNode = new Node;
        pNode->nValue = nVal;
        pNode->pNext = NULL;
        //  �ŵ�������
        if (m_pHead == NULL)
        {
            m_pHead = pNode;
            m_pEnd = pNode;
        }
        else
        {
            m_pEnd->pNext = pNode;
            m_pEnd = pNode;
        }
        m_nSize++;
    }
    void Pop_Front() // ��ͷɾ��
    {
        if (m_pHead == 0) //  û�нڵ�
            return;

        if (m_pHead == m_pEnd) //  һ���ڵ�
        {
            delete m_pHead;
            m_pHead = 0;
            m_pEnd = 0;
            m_nSize = 0;
            return;
        }

        //  ����ڵ�
        Node *pDel = m_pHead;
        m_pHead = m_pHead->pNext;
        delete pDel;
        pDel = NULL;
        m_nSize--;
    }
    void Pop_Back() // ��ͷɾ��
    {
        if (m_pHead == 0) //  û�нڵ�
            return;

        if (m_pHead == m_pEnd) //  һ���ڵ�
        {
            delete m_pHead;
            m_pHead = 0;
            m_pEnd = 0;
            m_nSize = 0;
            return;
        }

        //  ����ڵ�
        Node *pDel = m_pHead;
        while (pDel->pNext->pNext != NULL)
            pDel = pDel->pNext;

        delete m_pEnd;
        m_pEnd = pDel;
        m_pEnd->pNext = 0;
        m_nSize--;
    }
    void Show()
    {
        Node *pTemp = m_pHead;
        while (pTemp)
        {
            cout << pTemp->nValue << " ";
            pTemp = pTemp->pNext;
        }
    }
};

int main()
{
    CList lst1;
    lst1.Show();
    cout << endl
         << "=================================" << endl;

    system("pause");
    return 0;
}