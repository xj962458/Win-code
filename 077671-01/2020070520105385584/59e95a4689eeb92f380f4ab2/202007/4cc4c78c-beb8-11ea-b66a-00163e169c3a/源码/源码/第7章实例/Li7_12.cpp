//����Li7_12.cpp
//Ӧ��ʵ��
#include <iostream>
using namespace std;
template <typename NodeType> class Node;          //���ṹ
template <typename NodeType>class DoubleLinkList; //˫��������
template <typename NodeType>                      //����ģ��
class Node
{
	friend class DoubleLinkList<NodeType>;     //��Ԫ
	private:
		NodeType Data;                         //ģ�����͵Ľ��    
		Node <NodeType> *NextNode;             //ǰ��ָ��
		Node <NodeType> *PreviousNode;         //����ָ��
    public:
		Node();
		Node(NodeType&Value);
		~Node();                               //��������
};
template <typename NodeType>
class DoubleLinkList
{ 
    private:
        Node <NodeType> *FirstNode;           //�����ײ�ָ��
        Node <NodeType> *RearNode;            //����β��ָ��
    public:
	    DoubleLinkList();                     //˫�������캯��
	    ~DoubleLinkList();                    //˫��������������
        bool IsEmpty();                       //�ж��Ƿ��ǿ�����
	    void InsertAtFront(NodeType&Value);   //����������ͷ
	    void InsertAtRear(NodeType&Value);    //����������β
	    bool RemoveFromFront();               //ɾ�������ײ�һ����� 
	    bool RemoveFromRear();                //ɾ������β��һ�����
	    void TraverseForward();               //�������ײ���ʼ����������
	    void TraverseBackwards();             //������β����ʼ���������� 
	    Node<NodeType> *CreateNode(NodeType&Value);//��������
};
int main()
{
	DoubleLinkList< int > List;
	int Value=0,Option=0;
	do{  
		cout<<endl
			<<"        ˫������˵�"<<endl
			<<" 1. �������ײ�����һ����� "<<endl
			<<" 2. ������β������һ����� "<<endl
			<<" 3. �������ײ�ɾ��һ����� "<<endl
			<<" 4. ������β��ɾ��һ����� "<<endl
			<<" 5. �������ײ���ʼ���������� "<<endl
			<<" 6. ������β����ʼ���������� "<<endl
			<<" 0. �˳� "<<endl
			<<"���ѡ��";
		cin>>Option;
		switch(Option)
		{
		case 1:
			{cout<<"���������ݣ�";
			 cin>>Value;
			 List.InsertAtFront(Value);
			 break;}
        case 2:
			{cout<<"���������ݣ�";
			 cin>>Value;
			 List.InsertAtRear(Value);
			 break;}
        case 3:
			{List.RemoveFromFront();
			 break;}
		case 4:
			{List.RemoveFromRear();
			 break;}
		case 5:
			{List.TraverseForward();
			 break;}
		case 6:
			{List.TraverseBackwards();
			 break;}
		}
     }
	 while(Option!=0);
	 return 0;
}
template<typename NodeType>
Node<NodeType>::Node():Data(NULL),NextNode(NULL),PreviousNode(NULL){}
template<typename NodeType>
Node<NodeType>::Node(NodeType&Value):Data(Value),NextNode(NULL),PreviousNode(NULL){}
template<typename NodeType>
Node<NodeType>::~Node(){}
template<typename NodeType>
DoubleLinkList<NodeType>::DoubleLinkList():FirstNode(NULL),RearNode(NULL){}
template<typename NodeType>
DoubleLinkList<NodeType>::~DoubleLinkList()
{ 
	Node<NodeType> *CurrentNode=FirstNode,*TempNode;
	while(CurrentNode!=NULL)
		{TempNode=CurrentNode;
         CurrentNode=CurrentNode->NextNode;//��ǰָ���ƶ�����һ���
		 delete TempNode;//ɾ�����
		}
}
template <typename NodeType>
bool DoubleLinkList<NodeType>::IsEmpty()
{ 
	if(FirstNode==NULL)
		return true;
    else 
		return false;
}
template<typename NodeType>
Node<NodeType> *DoubleLinkList<NodeType>::CreateNode(NodeType&Value)
{
	Node<NodeType> *NewNode= new Node<NodeType>(Value);
	return NewNode;
}
template<typename NodeType>
void DoubleLinkList<NodeType>::InsertAtFront(NodeType&Value)
{
	Node<NodeType> *NewNode=CreateNode(Value);
	if(IsEmpty())//�ж�����Ϊ�շ�
		{FirstNode=RearNode=NewNode;}
	else
		{FirstNode->PreviousNode=NewNode;
	     NewNode->NextNode=FirstNode;
		 FirstNode=NewNode;
		 FirstNode->PreviousNode=NULL;}
	cout<<"���"<<FirstNode->Data<<"�ɹ����롣"<<endl;
}
template <typename NodeType>
void DoubleLinkList<NodeType>::InsertAtRear(NodeType&Value)
{  
	Node<NodeType> *NewNode=CreateNode(Value);
	if(IsEmpty())//�ж�����Ϊ�շ�
		{FirstNode=RearNode=NewNode;}
	else
		{NewNode->PreviousNode=RearNode;
	     RearNode->NextNode=NewNode;
		 RearNode=NewNode;
		 RearNode->NextNode=NULL;}
	cout<<"���"<<RearNode->Data<<"�ɹ����롣"<<endl;
}
template<typename NodeType>
bool DoubleLinkList<NodeType>::RemoveFromFront()
{ 
	if(IsEmpty())//�ж�����Ϊ�շ�
		{cout<<endl<<"û���������ܽ���ɾ����";
	     return false;}
	else 
		{Node<NodeType> *CurrentNode=FirstNode;
       	if(FirstNode==RearNode)
			FirstNode=RearNode=NULL;
		else
			{
			 FirstNode=FirstNode->NextNode;
		     FirstNode->PreviousNode=NULL;}
		delete CurrentNode;
		cout<<endl<<"���ɾ���ɹ���"<<endl;
		return true;}
}
template <typename NodeType>
bool DoubleLinkList<NodeType>::RemoveFromRear()
{
	if(IsEmpty())//�ж�����Ϊ�շ�
		{cout<<endl<<"û���������ܽ���ɾ����";
	     return false;}
	else 
		{Node<NodeType> *TempNode=RearNode;
	     if(FirstNode==RearNode)
			 FirstNode=RearNode=NULL;
		 else 
		 {RearNode=RearNode->PreviousNode;
		 RearNode->NextNode=NULL;}
		 delete TempNode;
		 cout<<endl<<"���ɾ���ɹ���";
		 return true;}
}
template<typename NodeType>
void DoubleLinkList<NodeType>::TraverseForward()
{ 
	Node<NodeType> *CurrentNode=FirstNode;
    if(IsEmpty())//�ж�����Ϊ�շ�
		{
		cout<<"û������û�н�������"<<endl;
		return;
		}
	cout<<endl<<"���ײ���ʼ�������:"<<endl;
	while(CurrentNode!=NULL)
		{cout<<CurrentNode->Data<<"  ";
	     CurrentNode=CurrentNode->NextNode;}
}
template<typename NodeType>
void DoubleLinkList<NodeType>::TraverseBackwards()
{
	if(IsEmpty())//�ж�����Ϊ�շ�
		{
		cout<<"û������û�н�������"<<endl;
		return;
		}
	Node<NodeType> *CurrentNode=RearNode;
	cout<<endl<<"��β����ʼ�������:"<<endl;
	while(CurrentNode!=NULL)
		{cout<<CurrentNode->Data<<"   ";
	     CurrentNode=CurrentNode->PreviousNode;}
}
