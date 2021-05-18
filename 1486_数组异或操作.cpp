/*************************************************************************
    > File Name: 1486_数组异或操作.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月07日 星期五 13时58分01秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int ret = start;
        for(int i = 1; i < n; ++i) {
            ret ^= (start + 2*i);
        }
        return ret;
    }
};
