#include <iostream>
#include <stack>
using namespace std;
void trans(char *exp, char postexp[])
{
    char e;
    stack<char> Optr;    //定义运算符栈（顺序栈）指针
    int i = 0;           //i作为postexp的下标
    while (*exp != '\0') //exp表达式未扫描完时循环
    {
        switch (*exp) //根据元素类型,执行相应操作
        {
        case '(':
            Optr.push('('); //判定为左括号,入运算符栈,继续扫描其它字符
            exp++;          //继续扫描其他字符
            break;
        case ')': //判定为右括号,则运算符出栈依次放入postexp字符数组中
            e = Optr.top();
            Optr.pop();
            while (e != '(') //不为'('时循环,直到碰的'('结束,左括弧不存入
            {
                postexp[i++] = e; //将（运算符）e存放到postexp中,
                e = Optr.top();
                Optr.pop();
            }
            exp++; //继续扫描其他字符
            break;
        case '+': //为加或减号时,栈里的运算符存入postexp,直到栈空或者
        case '-':
            while (!Optr.empty()) //栈空时退出循环
            {
                e = Optr.top();
                if (e != '(') //e不是'('
                {
                    postexp[i++] = e; //将(运算符）e存放到postexp中
                    e = Optr.top();
                    Optr.pop();
                }
                else
                    break; //碰到左括弧时,退出循环
            }
            Optr.push(*exp);
            exp++; //继续扫描其他字符
            break;
        case '*': //判定为'*'或'/'号,栈里*和/运算符全部存入postexp
        case '/':
            while (!Optr.empty()) //栈不空循环
            {
                e = Optr.top();
                if (e == '*' || e == '/') //e为'*'或'/'运算符
                {
                    postexp[i++] = e; //将('*'或'/'运算符)e存放到postexp中
                    e = Optr.top();
                    Optr.pop();
                }
                else //e为非'*'或'/'运算符时退出循环
                    break;
            }
            Optr.push(*exp);
            exp++; //继续扫描其他字符
            break;
        default:                               //处理数字字符
            while (*exp >= '0' && *exp <= '9') //转存数字字符,
            {
                postexp[i++] = *exp; //直接将数字字符存储字符数组postexp中
                exp++;
            }                   //直到出现非数字字符时结束,此时再增加一个#
            postexp[i++] = '#'; //增加#或者非数字字符,标识一个数值串结束
        }
    }
    while (!Optr.empty()) //此时exp扫描完毕,栈元素全部放入postexp
    {
        e = Optr.top();
        Optr.pop();
        postexp[i++] = e; //将e存放到postexp中
    }
    postexp[i] = '\0'; //给postexp表达式添加字符数组元素结束标识
}

//计算后缀表达式(已存储在postexp数组中）的值。
double compvalue(char *postexp)
{
    double d, a, b, c, e;
    stack<char> Opnd;        //定义操作数栈
    while (*postexp != '\0') //postexp字符串未扫描完时循环
    {
        switch (*postexp)
        {
        case '+': //判定为'+'号
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            c = b + a; //计算c
            Opnd.push(c);
            break;
        case '-': //判定为'-'号
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            c = b - a;    //计算c
            Opnd.push(c); //将计算结果c进操作数栈Opnd
            break;
        case '*': //判定为'*'号
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            c = b * a;    //计算c
            Opnd.push(c); //将计算结果c进操作数栈Opnd
            break;
        case '/': //判定为'/'号
            a = Opnd.top();
            Opnd.pop();
            b = Opnd.top();
            Opnd.pop();
            if (a != 0)
            {
                c = b / a;    //计算c
                Opnd.push(c); //将计算结果c进操作数栈Opnd
                break;
            }
            else
            {
                printf("\n\t除零错误!\n");
                exit(0); //异常退出
            }
            break;
        default:                                           //处理数字字符'0'-'9'
            d = 0;                                         //转换成对应的数值存放到d中
            while ((*postexp >= '0') && (*postexp <= '9')) //碰到非数字字符时结束
            {
                d = 10 * d + *postexp - '0'; //连续数字串转换为数值,参与运算
                postexp++;                   //非数字字符'#'正好被废弃了-妙-
            }
            Opnd.push(d); //将连续数字字符串转换后的数值d进操作数栈Opnd
            break;        //等待参与运算
        }
        postexp++; //继续处理其他字符
    }
    e = Opnd.top(); //取操作数栈Opnd栈顶元素（存放运算结果）,赋值给e返回
    return e;       //返回e （结果）
}
//建立如下主函数调用上述算法实现算术表达式的求解
int main()
{
    char exp[] = "(2+3)*6+8*5+4"; //可将exp改为键盘输入
    //char exp[50];
    //gets(str);//输入表达式字符串
    //puts(str);//输出表达式字符串
    char postexp[100];
    trans(exp, postexp);
    cout << "中缀表达式:" << exp << endl;
    cout << "后缀表达式:" << postexp << endl;
    cout << "表达式的值:" << compvalue(postexp) << endl;
    return 0;
}
