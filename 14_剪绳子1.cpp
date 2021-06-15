/*************************************************************************
    > File Name: 14_剪绳子1.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月30日 星期二 19时09分05秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // 动态规划
    // f(n) = f(x)*f(n-x)
    // 2 <= n <= 58
    int cuttingRope(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        vector<int> ret{0, 1};
        for(auto i = 2; i <= n; ++i) {
            int max = i;
            for(auto x = 1; x < i; ++x) {
                if(ret[x] * ret[i - x] > max) {
                    max = ret[x] * ret[i - x];
                }
            }
            ret.push_back(max);
        }
        return ret[n];
    }

    int cuttingRope2(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        int th = n / 3;
        switch(n % 3) {
            case 0:
                return std::pow(3, th);
            case 1:
                return std::pow(3, th - 1) * 4;
            case 2:
                return std::pow(3, th) * 2;
        }
        return 0;
    }
};

int main(void) {
    Solution s;
    cout << s.cuttingRope2(2) << endl;
    cout << s.cuttingRope2(10) << endl;
}
