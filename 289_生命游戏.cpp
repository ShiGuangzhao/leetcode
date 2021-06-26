#include <iostream>

class Solution {
private:
    vector<pair<int,int>> neibor{{1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, -1},
        {-1, -1}, {-1, 0}, {-1, 1}};
public:
    // 用自己来做标记，不用辅助空间
    void gameOfLife(vector<vector<int>>& board) {
        auto xsize = board.size(), ysize = board[0].size();
        for(auto i = 0; i < xsize; ++i) {
            for(auto j = 0; j < ysize; ++j) {
                if(board[i][j] == 0)    board[i][j] = -1;
            }
        }
        for(auto i = 0; i < xsize; ++i) {
            for(auto j = 0; j < ysize; ++j) {
                if(board[i][j] > 0) {
                    for(auto &p: neibor) {
                        auto x = i + p.first;
                        auto y = j + p.second;
                        if(x >= 0 and x < xsize and y >= 0 and y < ysize) {
                            board[x][y] += (board[x][y] > 0? 1: -1);
                        }
                    }
                }
            }
        }
        for(auto i = 0; i < xsize; ++i) {
            for(auto j = 0; j < ysize; ++j) {
                int count = std::abs(board[i][j]) - 1;
                if(board[i][j] > 0) {
                    board[i][j] = (count < 2 or count > 3)? 0: 1; 
                }
                else {
                    board[i][j] = (count == 3)? 1: 0; 
                }
            }
        }
    }

    // 使用O(n)辅助空间计数
    void gameOfLife1(vector<vector<int>>& board) {
        auto xsize = board.size(), ysize = board[0].size();
        vector<vector<int>> count(xsize, vector(ysize, 0));
        for(auto i = 0; i < xsize; ++i) {
            for(auto j = 0; j < ysize; ++j) {
                if(board[i][j] == 1) {
                    for(auto &p: neibor) {
                        auto x = i + p.first;
                        auto y = j + p.second;
                        if(x >= 0 and x < xsize and y >= 0 and y < ysize) {
                            ++count[x][y];
                        }
                    }
                }
            }
        }
        for(auto i = 0; i < xsize; ++i) {
            for(auto j = 0; j < ysize; ++j) {
                if(board[i][j] == 1 and (count[i][j] < 2 or count[i][j] > 3)) {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 0 and count[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
