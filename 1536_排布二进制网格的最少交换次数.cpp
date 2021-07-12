/*************************************************************************
    > File Name: 1536_排布二进制网格的最少交换次数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月12日 星期一 14时42分41秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 首先将0的数量放到数组中
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> count;
        for(auto &line: grid) {
            count.push_back(0);
            for(auto it = line.rbegin(); it != line.rend(); ++it) {
                if(*it != 0)    break;
                ++count.back();
            }
        }
        // 计算交换


    }
};
