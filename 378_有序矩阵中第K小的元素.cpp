/*************************************************************************
    > File Name: 378_有序矩阵中第K小的元素.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月06日 星期二 13时18分19秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 暴力解法
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> sortM;
        auto count = 1;
        for(auto &line: matrix) {
            vector<int> tmp(matrix.size() * count++);
            std::merge(line.begin(), line.end(), sortM.begin(), sortM.end(), tmp.begin());
            sortM = tmp;
        }
        return sortM[k - 1];
    }
};
