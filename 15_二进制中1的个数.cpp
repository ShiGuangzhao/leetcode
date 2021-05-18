/*************************************************************************
    > File Name: 15_二进制中1的个数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月01日 星期四 14时06分26秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    // 暴力
    int hammingWeight1(uint32_t n) {
        int ret = 0;
        for(auto i = 0; i < 32; ++i) {
            ret += (n & 1);
            n = n >> 1;
        }
        return ret;
    }

    // 利用n&(n-1)
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n != 0) {
            n &= n - 1;
            ++ret;
        }
        return ret;
    }
};
