/*************************************************************************
    > File Name: 207_课程表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月08日 星期二 14时20分38秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
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
            ++indegree;
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
        unordered_map<int, struct NodeInfo> nodeMap;
        for(auto i = 0; i < numCourses; ++i) {
            nodeMap.insert({i, nodeInfo_t()});
        }
        for(auto &line: prerequisites) {
            nodeMap[line[1]].push(line[0]);
        }
        while(nodeMap.size() > 1) {
            for(auto &info: nodeMap) {
                if(info.second.indegree == 0) {
                    for(auto num: info.second.nexts) {
                        --nodeMap[num].indegree;
                    }
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};
