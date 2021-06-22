/*************************************************************************
    > File Name: 529_扫雷游戏.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月20日 星期四 17时04分36秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. 输入board和click，对应位置可能是M或E
// 2. 如果是M，修改为X并返回
// 3. 如果是E，E 入队列：
//      * 出队一个E， 旁边可能为 B、E、数字、M
//      * 设置计数器，扫描八个位置，为M计数器++
//          * 如果计数结果不为0，位置设置为数字，break
//          * 为0则设置为B，旁边的E入队列
//      * 循环直到队列空

class Solution {
private:
    bool isBundage(vector<vector<char>>& board, const vector<int>& click) {
        return (click[0] < 0 \
                || click[0] >= board.size() \
                || click[1] < 0 \
                || click[1] >= board[0].size());
    }

    void BST(vector<vector<char>>& board, vector<int>& click) {
        queue<vector<int>> Q;
        vector<int> E;
        Q.push(click);
        while(!Q.empty()) {
            E = Q.front();
            Q.pop();
            if((board[E[0]][E[1]]) != 'E') {
                continue;
            }
            // cout << Q.size() << endl;
            size_t count = 0;
            for(auto i: {-1, 0, 1}) {
                for(auto j: {-1, 0, 1}) {
                    if(i == 0 && j == 0) {
                        continue;
                    }
                    if(!isBundage(board, {E[0] + i, E[1] + j}) \
                            && (board[E[0] + i][E[1] + j]) == 'M') {
                        count++;
                    }
                }
            }
            if(count != 0) {
                board[E[0]][E[1]] = (char)(count + 48);
            }
            else {
                board[E[0]][E[1]] = 'B';
                for(auto i: {-1, 0, 1}) {
                    for(auto j: {-1, 0, 1}) {
                        if(i == 0 && j == 0) {
                            continue;
                        }
                        if(!isBundage(board, {E[0] + i, E[1] + j}) \
                                && (board[E[0] + i][E[1] + j]) == 'E') {
                            Q.push({E[0] + i, E[1] + j});
                        }
                    }
                }
            }
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        auto &cli = board[click[0]][click[1]];
        if(cli == 'M') {
            cli = 'X';
        }
        else {      // cli = E
            BST(board, click);
        }
        return board;
    }
};
