/*************************************************************************
    > File Name: 4_二维数组中查找.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月13日 星期六 11时43分11秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 查找最左列：位于第一个大于target的元素列（不含）之前
// 查找最右列：位于第一个大于target的元素列（含）之后

class Solution {
private:
    using callback_t = int (*)(vector<vector<int>>& matrix, int j, int arg);

    // 寻找第一个大于target的index
    int devideSearch(vector<vector<int>>& matrix, int begin, int end, int target, int arg, callback_t value) {
        if(value(matrix, begin, arg) >= target) {
            return begin;
        }
        if(value(matrix, end, arg) < target) {
            return end + 1;
        }
        while(1) {
            auto half = (begin + end) / 2;
            if(value(matrix, half, arg) > target) {
                end = half;
            }
            else {
                begin = half;
            }
            if(end - begin <= 1) {
                return end;
            }
        }
    }

    int devideSearch1(vector<vector<int>>& matrix, int begin, int end, int target, int arg, callback_t value) {
        if(value(matrix, begin, arg) >= target) {
            return begin;
        }
        if(value(matrix, end, arg) < target) {
            return end + 1;
        }
        while(1) {
            auto half = (begin + end) / 2;
            if(value(matrix, half, arg) >= target) {
                end = half;
            }
            else {
                begin = half;
            }
            if(end - begin <= 1) {
                return end;
            }
        }
    }

public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty() || target < matrix[0][0]) {
            return false;
        }

        auto m = matrix.size();
        auto n = matrix[0].size();
        if(target > matrix[m - 1][n - 1]) {
            return false;
        }

        // 查找最左列：第left行之前（不含）
        auto left = devideSearch(matrix, 0, m - 1, target, 0,  
                [](vector<vector<int>> &matrix, int index, int arg) {
                return matrix[index][0];
                });
        // 查找最右列：第right行之后（含）
        auto right = devideSearch1(matrix, 0, m - 1, target, 0,
                [](vector<vector<int>> &matrix, int index, int arg) {
                return matrix[index][matrix[0].size() - 1];
                });
        // 查找最上行：第top列之前（不含）
        auto top = devideSearch(matrix, 0, n - 1, target, right, 
                [](vector<vector<int>> &matrix, int index, int arg) {
                return matrix[arg][index];
                });
        // 查找最下行：第bottom列之后（含）
        auto bottom = devideSearch1(matrix, 0, n - 1, target, left - 1, 
                [](vector<vector<int>> &matrix, int index, int arg) {
                return matrix[arg][index];
                });
        cout << left << right << top << bottom << endl;
        for(auto h = right; h < left; ++h) {
            for(auto l = bottom; l < top; ++l) {
                cout << h << l << endl;
                if(matrix[h][l] == target) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main(void) {
    vector<vector<int>> num{
        // {1, 2, 3},
        {3 }
    };
    Solution s;
    cout << s.findNumberIn2DArray(num, 3) << endl;
}
