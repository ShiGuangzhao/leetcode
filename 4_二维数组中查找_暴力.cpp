/*************************************************************************
    > File Name: 4_二维数组中查找.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月13日 星期六 11时43分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for(auto v: matrix) {
            if(std::find(v.begin(), v.end(), target) != v.end()) {
                return true;
            }
        }
        return false;
    }
};

int main(void) {
    vector<vector<int>> num{
        // {1, 2, 3},
        {2, 3, 4}
    };
    Solution s;
    cout << s.findNumberIn2DArray(num, 3) << endl;
}
