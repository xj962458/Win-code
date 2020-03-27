#include <iostream>
using namespace std;
 
int main()
{
    char c;
    int isLowercaseVowel, isUppercaseVowel;
 
    cout << "输入一个字母: ";
    cin >> c;
 
    // 小写字母元音
    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
 
    // 大写字母元音
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
 
    // if 语句判断
    if (isLowercaseVowel || isUppercaseVowel)
        cout << c << " 是元音";
    else
        cout << c << " 是辅音";
 
    return 0;
}
