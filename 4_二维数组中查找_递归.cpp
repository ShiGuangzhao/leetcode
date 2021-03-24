/*************************************************************************
    > File Name: 4_二维数组中查找.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月13日 星期六 11时43分11秒
 ************************************************************************/

#include <ios>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    using Mat_t = vector<vector<int>>;
    bool findNumberIn2DArray_RightTop(Mat_t &matrix, int m, int n, int target) {
        if(n < 0 || m == matrix.size()) {
            return false;
        }
        if(matrix[m][n] == target) {
            return true;
        }
        else if(matrix[m][n] > target) {
            return findNumberIn2DArray_RightTop(matrix, m, n - 1, target);
        }
        else {
            return findNumberIn2DArray_RightTop(matrix, m + 1, n, target);
        }
    }


public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        return findNumberIn2DArray_RightTop(matrix, 0, matrix[0].size() - 1, target);
    }

};

int main(void) {
    vector<vector<int>> num{
        {1, 2, 3},
        {3, 4, 5 }
    };
    Solution s;
    cout << std::boolalpha << s.findNumberIn2DArray(num, 3) << endl;
}
