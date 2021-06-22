/*************************************************************************
    > File Name: 13_LCP_寻宝.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年07月29日 星期三 10时14分55秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::string;
using std::queue;

class Solution {
private:
    const int INFINITY = -2;
    const int UNKNOWN = -1;
    struct xyPos {
        int x;
        int y;
        xyPos(int x_in, int y_in): x(x_in), y(y_in) {}
        xyPos(int x_up, int y_up, xyPos xyTemp):
            x(xyTemp.x + x_up), y(xyTemp.y + y_up) {}
    };

    bool isOutside(xyPos xyTemp, vector<string>& maze) {
        return xyTemp.x >= 0 && xyTemp.y >= 0 && xyTemp.x < maze.size() \
                           && xyTemp.y < maze[0].size();
    }

    bool isOutside(int x, int y, vector<string>& maze) {
        return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size();
    }

    // 输入位置和字符串，返回点到点的最小距离
    void bfs(int Mx, int My, vector<string>& maze) {
        int dist[maze.size()][maze[0].size()];
        for(auto &line: dist) {     // 节点设置为未知
            for(auto &i: line) {
                i = UNKNOWN;
            }
        }
        dist[Mx][My] = 0;   // 起点
        queue<xyPos> q;
        xyPos xyTemp(Mx, My);
        q.push(xyTemp);
        while(!q.empty()) {
            // 出队列一个元素
            xyTemp = q.front();
            q.pop();
            // 访问临近元素，如果临近元素存在，如果为墙壁则距离设为无穷大
            // 否则等于原距离加一，并入队列
            for(auto adjPos: {xyPos(-1, 0, xyTemp), xyPos(1, 0, xyTemp), \
                    xyPos(0, -1, xyTemp), xyPos(0, 1, xyTemp)}) {
                if(!isOutside(adjPos, maze)) {
                    if(maze[adjPos.x][adjPos.y] == '#') {       // 墙壁
                        dist[adjPos.x][adjPos.y] = INFINITY;
                    }
                    else if(dist[adjPos.x][adjPos.y] != UNKNOWN)    {   // 未被访问过
                        dist[adjPos.x][adjPos.y] = dist[xyTemp.x][xyTemp.y] + 1;
                        q.push(adjPos);
                    }
                }
            }
        }
        // 验证是否所有必要节点都被访问过


    }
public:
    int minimalSteps(vector<string>& maze) {
        bfs(1, 1, maze);
        return 0;
    }
};
