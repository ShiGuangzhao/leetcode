/*************************************************************************
    > File Name: 279_完全平方数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月23日 星期三 13时10分30秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划
    // 超出时间限制
    int numSquares(int n) {
        vector<int> ret(n + 1, 0);
        auto i = 1, pow = 1;
        while(pow < n) {
            ret[pow] = 1;
            ret[pow + 1] = 2;
            ++i;
            pow = i * i;
        }
        if(pow == n)        return 1;
        if(ret[n] != 0)     return ret[n];

        for(i = 2; i < ret.size(); ++i) {
            if(ret[i] == 0) {
                ret[i] = ret[i - 1]; 
                for(auto j = 2; j * j <= i; ++j) {
                    if(ret[i] > ret[i - j * j]) {
                        ret[i] = ret[i - j * j];
                    }
                }
                ret[i] += 1;
            }
        }
        return ret[n];
    }
};
