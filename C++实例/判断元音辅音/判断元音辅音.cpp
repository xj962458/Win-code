#include <iostream>
using namespace std;
 
int main()
{
    char c;
    int isLowercaseVowel, isUppercaseVowel;
 
    cout << "����һ����ĸ: ";
    cin >> c;
 
    // Сд��ĸԪ��
    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
 
    // ��д��ĸԪ��
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
 
    // if ����ж�
    if (isLowercaseVowel || isUppercaseVowel)
        cout << c << " ��Ԫ��";
    else
        cout << c << " �Ǹ���";
 
    return 0;
}