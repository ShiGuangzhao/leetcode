/*************************************************************************
    > File Name: 12_矩阵中的路径.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月30日 星期二 10时51分27秒
 ************************************************************************/

#include <ios>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
    using point = std::pair<int, int>;
    // 计算附近正确的点
    vector<point> clacPoints(vector<vector<char>> &board, char key, point &start) {
        vector<point> ret;
        if(start.first - 1 >= 0 && board[start.first - 1][start.second] == key) {
            ret.emplace_back(start.first - 1, start.second);
        }
        if(start.second - 1 >= 0 && board[start.first][start.second - 1] == key) {
            ret.emplace_back(start.first, start.second - 1);
        }
        if(start.first + 1 < board.size() && board[start.first + 1][start.second] == key) {
            ret.emplace_back(start.first + 1, start.second);
        }
        if(start.second + 1 < board[0].size() && board[start.first][start.second + 1] == key) {
            ret.emplace_back(start.first, start.second + 1);
        }
        return ret;
    }

    // 每个的board不同，所以不能用引用
    // 上一层递归选择正确的起点
    // 本次递归更改该点为0，并开始下一次递归
    bool exist_swaper(vector<vector<char>> board, string word, point start) {
        if(word.empty()) {
            return true;
        }
        board[start.first][start.second] = 0;
        auto nexts = clacPoints(board, word[0], start);
        for(auto p: nexts) {
            if(exist_swaper(board, word.substr(1), p))
                return true;
        }
        return false;
    }

public:
    // 使用一个辅助矩阵标记位置是否被经过过，如果经过过则置为0
    // 使用递归方式计算
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) {
            return true;
        }
        for(auto x = 0; x < board.size(); ++x) {
            for(auto y = 0; y < board[0].size(); ++y) {
                if(board[x][y] == word[0] && exist_swaper(board, word.substr(1), {x, y})) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main(void) {
    vector<vector<char>> board {
        {'a', 'b'}
    };
    Solution s;
    cout << std::boolalpha << s.exist(board, "cd") << endl;
}
