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
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = 0;
        int n = matrix[0].size() - 1;
        auto mSize = matrix.size();
        while(n >= 0 && m < mSize) {
            if(matrix[m][n] == target)  return true;
            else if(matrix[m][n] > target)  n--;
            else    ++m;
        }
        return false;
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
