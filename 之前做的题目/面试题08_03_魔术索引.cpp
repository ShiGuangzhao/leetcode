/*************************************************************************
    > File Name: 面试题08_03_魔术索引.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月31日 星期五 11时09分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int i = 0;
        for(auto n: nums) {
            if(n == i++) {
                return n;
            }
        }
        return -1;
    }
};
