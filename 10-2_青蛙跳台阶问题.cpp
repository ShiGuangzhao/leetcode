/*************************************************************************
    > File Name: 10-2_青蛙跳台阶问题.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月24日 星期三 11时03分50秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划？
    int numWays(int n) {
        vector<int> f{1, 1, 2, 3};
        for(int i = 4; i <= n; ++i) {
            auto tmp = i / 2;
            if(i % 2 == 0) {
                f.push_back(((uint64_t)f[tmp]*f[tmp] + (uint64_t)f[tmp-1]*f[tmp-1]) % 1000000007);
            }
            else {
                f.push_back(((2*(uint64_t)f[tmp-1] + f[tmp]) * f[tmp]) % 1000000007);
            }
        }
        return f[n];
    }
    // 递归
    int numWays1(int n) {
        if(n == 0) {
            return 1;
        }
        else if(n <= 3) {
            return n;
        }
        else {
            auto tmp = n / 2;
            auto ftmp = numWays1(tmp);
            auto ftmp_1 = numWays1(tmp - 1);
            if(n % 2 == 0) {
                return ((uint64_t)ftmp*ftmp + (uint64_t)ftmp_1*ftmp_1) % 1000000007;
            }
            else {
                return ((2*(uint64_t)ftmp_1 + ftmp) * ftmp) % 1000000007;
            }
        }
    }
    // fib
    int numWays2(int n) {
        if(n == 0) {
            return 1;
        }
        else if(n == 1) {
            return 1;
        }
        else {
            int fn_2 = 1, fn_1 = 1;
            for(auto i = 2; i < n; ++i) {
                auto tmp = fn_1;
                fn_1 = (fn_1 + fn_2) % 1000000007;
                fn_2 = tmp;
            }
            return (fn_1 + fn_2) % 1000000007;
        }
    }

};

int main(void) {
    Solution s;
    for(auto i = 0; i < 50; ++i) {
        cout << i << ": " << s.numWays2(i) << endl;
    }
}
