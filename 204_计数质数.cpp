/*************************************************************************
    > File Name: 204_计数质数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月06日 星期日 23时22分54秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 4) {
            return n < 3? 0: n - 2;
        }
        // 用来存储素数
        vector<int> prime{2, 3};
        bool flag = true;
        for(int i = 5; i < n; ++i) {
            flag = true;
            auto half = std::sqrt(i);
            for(auto j: prime) {
                if(j > half) {
                    break;
                }
                if(i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag)    prime.push_back(i);
        }
        return prime.size();
    }
};
