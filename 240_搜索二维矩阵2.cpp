/*************************************************************************
    > File Name: 240_搜索二维矩阵2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月22日 星期二 13时00分21秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力搜索
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for(auto &line: matrix) {
            for(auto i: line) {
                if(i == target) {
                    return true;
                }
            }
        }
        return false;
    }

    // 从左上角开始搜索
    // 大于左上角则++y，小于则--x
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix[0].size() - 1;
        int y = 0;
        while(x >= 0 and y < matrix.size()) {
            if(matrix[y][x] == target)      return true;
            else if(matrix[y][x] > target)  --x;
            else    ++y;
        }
        return false;
    }
};
