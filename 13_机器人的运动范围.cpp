/*************************************************************************
    > File Name: 13_机器人的运动范围.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月30日 星期二 14时04分53秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 从0开始深度优先搜索
    // 经过过的不再经过，所以需要标记
    // 经过一个点时还要经过附近的几个点
    int movingCount(int m, int n, int k) {
        // 初始化一个矩阵，用来标记可访问性
        // 只要经过过肯定不能访问
        // true表示未访问过
        vector<vector<bool>> mat(m, vector<bool>(n, true));
        xSize = m;
        ySize = n;
        key = k;
        dfs(mat, 0, 0);
        return count;
    }

private:
    int xSize;
    int ySize;
    int count = 0;
    int key;
    void dfs(vector<vector<bool>> &mat, int x, int y) {
        if(x < 0 || y < 0 || x >= xSize || y >= ySize
                || mat[x][y] == false) {    // 不可访问或已经访问过
            return;
        }
        mat[x][y] = false;
        if(!pointAllow(x, y, key)) {
            return;
        }
        ++count;
        dfs(mat, x - 1, y);
        dfs(mat, x, y - 1);
        dfs(mat, x + 1, y);
        dfs(mat, x, y + 1);
    }

    bool pointAllow(int x, int y, int k) {
        int sum = 0;
        while(x != 0) {
            sum += x%10;
            x /= 10;
        }
        while(y != 0) {
            sum += y%10;
            y /= 10;
        }
        return sum <= k;
    }
};

int main(void) {
    Solution s;
    cout << s.movingCount(2, 3, 1) << endl;
}
