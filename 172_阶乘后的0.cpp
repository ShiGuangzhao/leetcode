/*************************************************************************
    > File Name: 172_阶乘后的0.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月01日 星期二 14时26分08秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        int tmp = 5;
        while(n >= tmp) {
            ret += n / tmp;
            tmp *= 5;
        }
        return ret;
    }
};

