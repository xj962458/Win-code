#include <iostream>
using namespace std;
 
int main() {
    int n1, n2, hcf;
    cout << "输入两个整数: ";
    cin >> n1 >> n2;
 
    // 如果 n2 大于 n1 交换两个变量
    if ( n2 > n1) {   
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }
    
    for (int i = 1; i <=  n2; ++i) {
        if (n1 % i == 0 && n2 % i ==0) {
            hcf = i;
        }
    }
 
    cout << "HCF = " << hcf;
    return 0;
}