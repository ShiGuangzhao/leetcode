/*************************************************************************
    > File Name: 130_被围绕的区域.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月18日 星期二 20时11分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> cors{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    inline bool isVaildPonits(int x, int y, int xSize, int ySize) {
        return x >= 0 and x < xSize and y >= 0 and y < ySize;
    }

    // (x, y)为标记为O的边缘节点
    void bfs(vector<vector<char>> &board, vector<vector<bool>> &mark, int x, int y) {
        mark[x][y] = true;
        queue<pair<int, int>> points;
        points.push({x, y});
        mark[x][y] = true;
        int xSize = board.size();
        int ySize = board[0].size();

        while(!points.empty()) {
            x = points.front().first;
            y = points.front().second;
            points.pop();
            for(auto cor: cors) {
                if(isVaildPonits(x + cor.first, y + cor.second, xSize, ySize)    // index合法
                        and board[x + cor.first][y + cor.second] == 'O'          // 节点为O
                        and mark[x + cor.first][y + cor.second] == false) {      // 未被访问过
                    points.push({x + cor.first, y + cor.second});
                    mark[x + cor.first][y + cor.second] = true;
                }
            }
        }
    }

public:
    // 从边缘开始遍历
    // 边缘的O是不会被围绕的，与边缘O连接的也是不会被围绕的
    // 使用辅助空间标记不被围绕的O
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));
        int x, y;
        int xSize = board.size();
        int ySize = board[0].size();
        for(x = 0; x < xSize; ++x) {
            for(y = 0; y < ySize; ++y) {
                if(x != 0 and y != 0 and  x != xSize - 1 and y != ySize - 1)    continue;
                if(board[x][y] == 'O' and !mark[x][y])  bfs(board, mark, x, y);
            }
        }
        for(x = 0; x < xSize; ++x) {
            for(y = 0; y < ySize; ++y) {
                if(board[x][y] == 'O' and !mark[x][y])  board[x][y] = 'X';
            }
        }
    }
};
