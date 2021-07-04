/*************************************************************************
    > File Name: 247_前k个高频元素.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月29日 星期二 13时30分50秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(auto n: nums) {
            ++count[n];
        }
        std::priority_queue<int> heap;
        for(auto c: count) {
            heap.push(c.second);
        }
        while(--k > 0) {
            heap.pop();
        }
        vector<int> ret;
        for(auto p: count) {
            if(p.second >= heap.top()) {
                ret.push_back(p.first);
            }
        }
        return ret;
    }
};
