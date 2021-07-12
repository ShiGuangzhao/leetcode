/*************************************************************************
    > File Name: 275_H指数2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月12日 星期一 14时02分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // h 篇论文至少引用 h 次
    // 即 citations[n-h] >= h，且citations[n - h - 1] <= h
    // 暴力解法
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0 or citations[0] >= n) {
            return n;
        }
        int h = n;
        while(--h > 0) {
            if(citations[n - h] >= h and citations[n - h - 1] <= h) {
                return h;
            }
        }
        return h;
    }
};
