#include <iostream>
#include <stack>
using namespace std;
void trans(char *exp, char postexp[])
{
    char e;
    stack<char> Optr;    //���������ջ��˳��ջ��ָ��
    int i = 0;           //i��Ϊpostexp���±�
    while (*exp != '\0') //exp���ʽδɨ����ʱѭ��
    {
        switch (*exp) //����Ԫ������,ִ����Ӧ����
        {
        case '(':
            Optr.push('('); //�ж�Ϊ������,�������ջ,����ɨ�������ַ�
            exp++;          //����ɨ�������ַ�
            break;
        case ')': //�ж�Ϊ������,���������ջ���η���postexp�ַ�������
            e = Optr.top();
            Optr.pop();
            while (e != '(') //��Ϊ'('ʱѭ��,ֱ������'('����,������������
            {
                postexp[i++] = e; //�����������e��ŵ�postexp��,
                e = Optr.top();
                Optr.pop();
            }
            exp++; //����ɨ�������ַ�
            break;
        case '+': //Ϊ�ӻ����ʱ,ջ������������postexp,ֱ��ջ�ջ���
        case '-':
            while (!Optr.empty()) //ջ��ʱ�˳�ѭ��
            {
                e = Optr.top();
                if (e != '(') //e����'('
                {
                    postexp[i++] = e; //��(�������e��ŵ�postexp��
                    e = Optr.top();
                    Optr.pop();
                }
                else
                    break; //����������ʱ,�˳�ѭ��
            }
            Optr.push(*exp);
            exp++; //����ɨ�������ַ�
            break;
        case '*': //�ж�Ϊ'*'��'/'��,ջ��*��/�����ȫ������postexp
        case '/':
            while (!Optr.empty()) //ջ����ѭ��
            {
                e = Optr.top();
                if (e == '*' || e == '/') //eΪ'*'��'/'�����
                {
                    postexp[i++] = e; //��('*'��'/'�����)e��ŵ�postexp��
                    e = Optr.top();
                    Optr.pop();
                }
                else //eΪ��'*'��'/'�����ʱ�˳�ѭ��
                    break;
            }
            Optr.push(*exp);
            exp++; //����ɨ�������ַ�
            break;
        default:                               //���������ַ�
            while (*exp >= '0' && *exp <= '9') //ת�������ַ�,
            {
                postexp[i++] = *exp; //ֱ�ӽ������ַ��洢�ַ�����postexp��
                exp++;
            }                   //ֱ�����ַ������ַ�ʱ����,��ʱ������һ��#
            postexp[i++] = '#'; //����#���߷������ַ�,��ʶһ����ֵ������
        }
    }
    while (!Optr.empty()) //��ʱexpɨ�����,ջԪ��ȫ������postexp
    {
        e = Optr.top();
        Optr.pop();
        postexp[i++] = e; //��e��ŵ�postexp��
    }
    postexp[i] = '\0'; //��postexp���ʽ����ַ�����Ԫ�ؽ�����ʶ
}

//�����׺���ʽ(�Ѵ洢��postexp�����У���ֵ��
double compvalue(char *postexp)
{
    double d, a, b, c, e;
    stack<char> Opnd;        //���������ջ
    while (*postexp != '\0') //postexp�ַ���δɨ����ʱѭ��
    {
        switch (*postexp)
        {
        case '+': //�ж�Ϊ'+'��
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            c = b + a; //����c
            Opnd.push(c);
            break;
        case '-': //�ж�Ϊ'-'��
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            c = b - a;    //����c
            Opnd.push(c); //��������c��������ջOpnd
            break;
        case '*': //�ж�Ϊ'*'��
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            c = b * a;    //����c
            Opnd.push(c); //��������c��������ջOpnd
            break;
        case '/': //�ж�Ϊ'/'��
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            if (a != 0)
            {
                c = b / a;    //����c
                Opnd.push(c); //��������c��������ջOpnd
                break;
            }
            else
            {
                printf("\n\t�������!\n");
                exit(0); //�쳣�˳�
            }
            break;
        default:                                           //���������ַ�'0'-'9'
            d = 0;                                         //ת���ɶ�Ӧ����ֵ��ŵ�d��
            while ((*postexp >= '0') && (*postexp <= '9')) //�����������ַ�ʱ����
            {
                d = 10 * d + *postexp - '0'; //�������ִ�ת��Ϊ��ֵ,��������
                postexp++;                   //�������ַ�'#'���ñ�������-��-
            }
            Opnd.push(d); //�����������ַ���ת�������ֵd��������ջOpnd
            break;        //�ȴ���������
        }
        postexp++; //�������������ַ�
    }
    e = Opnd.top(); //ȡ������ջOpndջ��Ԫ�أ������������,��ֵ��e����
    return e;       //����e �������
}
//�����������������������㷨ʵ���������ʽ�����
int main()
{
    char exp[] = "(2+3)*6+8*5+4"; //�ɽ�exp��Ϊ��������
    //char exp[50];
    //gets(str);//������ʽ�ַ���
    //puts(str);//������ʽ�ַ���
    char postexp[100];
    trans(exp, postexp);
    cout << "��׺���ʽ:" << exp << endl;
    cout << "��׺���ʽ:" << postexp << endl;
    cout << "���ʽ��ֵ:" << compvalue(postexp) << endl;
    return 0;
}
