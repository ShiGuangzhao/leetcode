/*************************************************************************
    > File Name: 10_斐波那契数列.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月23日 星期二 20时11分17秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        int fn_2 = 0, fn_1 = 1;
        for(auto i = 2; i < n; ++i) {
            auto tmp = fn_1;
            fn_1 = (fn_1 + fn_2) % 1000000007;
            fn_2 = tmp;
        }
        return (fn_1 + fn_2) % 1000000007;
    }
    // 超出时间限制
    int fib2(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        return fib2(n - 1) + fib2(n - 2);
    }
};

int main(void) {
    Solution S;
    cout << S.fib(45) << endl;
}
