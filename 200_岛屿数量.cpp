/*************************************************************************
    > File Name: 200_岛屿数量.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月06日 星期日 22时48分29秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    // bfs
    inline void bfs(vector<vector<char>> &grid, int x, int y) {
        queue<pair<int, int>> que;
        vector<pair<int, int>> diffVec{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int tmpX, tmpY;

        que.push({x, y});
        grid[x][y] = '0';
        while(!que.empty()) {
            auto point = que.front();
            que.pop();
            for(auto &diff: diffVec) {
                tmpX = point.first + diff.first;
                tmpY = point.second + diff.second;
                if(tmpX >= 0 and tmpX < grid.size()
                        and tmpY >= 0 and tmpY < grid[0].size()
                        and grid[tmpX][tmpY] == '1') {
                    que.push({tmpX, tmpY});
                    grid[tmpX][tmpY] = '0';
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(auto x = 0; x < grid.size(); ++x) {
            for(auto y = 0; y < grid[0].size(); ++y) {
                if(grid[x][y] == '1') {
                    ++ret;
                    bfs(grid, x, y);
                }
            }
        }
        return ret;
    }
};
