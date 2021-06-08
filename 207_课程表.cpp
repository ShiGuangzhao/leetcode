/*************************************************************************
    > File Name: 207_课程表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月08日 星期二 14时20分38秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    struct NodeInfo {
        int indegree;
        vector<int> nexts;
        
        NodeInfo(): indegree(0), nexts(vector<int>()) {
        }

        NodeInfo(int deg): indegree(deg), nexts(vector<int>()) {
        }

        void push(int i) {
            nexts.push_back(i);
        }
    };

    using nodeInfo_t = struct NodeInfo;

public:
    // 类似判断图有没有环？
    // 拓扑排序找不到入度为0的点，说明存在圈
    // 算法：
    // 使用数组记录入度，找到一个入度为0的点
    // 删除该点，并减小他指向点的入度
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 节点：入度，指向的节点
        vector<struct NodeInfo> nodeMap(numCourses, nodeInfo_t());
        for(auto &line: prerequisites) {
            nodeMap[line[1]].push(line[0]);
            ++nodeMap[line[0]].indegree;
            /* cout << "init: push " << line[0] << " to " << line[1] << endl; */
        }
        // 这种方法不好，题解中的深度/广度优先搜索更简化
        for(auto i = 0; i < numCourses; ++i) {
            auto del = std::find_if(nodeMap.begin(), nodeMap.end(), 
                                    [](nodeInfo_t a) {return a.indegree == 0;});
            /* cout << int(del - nodeMap.begin()) << " " << del->indegree << endl; */
            if(del == nodeMap.end()) {
                return false;
            }
            for(auto num: del->nexts) {
                --nodeMap[num].indegree;
            }
            /* cout << "del: " << info.first << endl; */
            del->indegree = INT32_MAX;
        }
        return true;
    }
};


int main(void) {
    int count = 5;
    vector<vector<int>> p{{4, 4}, {2, 4}, {3, 1}, {3, 2}};
    Solution s;
    cout << s.canFinish(count, p) << endl;
}
