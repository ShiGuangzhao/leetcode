/*************************************************************************
    > File Name: 191_位1的个数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 11时06分13秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t tmp = 1;
        for(auto i = 0; i < 32; ++i) {
            if((tmp & n) != 0) {
                ++count;
            }
            tmp = tmp << 1;
        }
        return count;
    }
};
