/*************************************************************************
    > File Name: 139_单词拆分.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月20日 星期四 14时29分47秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // 动态规划
    // 从后到前遍历，使用数组标记
    // 数组标记到下一跳的位置
    // 如果本位置合法则标记为自己
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto &w: wordDict) {
            dict.insert(w);
        }

        vector<int> mark(s.size(), -1);
        mark.back() = s.size() - dict.count(s.substr(s.size() - 1, 1));
        mark.push_back(s.size());

        for(int i = int(s.size()) - 2; i >= 0; --i) {
            auto end = i;
            mark[i] = mark[i + 1];
            while(end != s.size()) {
                end = mark[end + 1];
                if(dict.count(s.substr(i, end - i))) {
                    mark[i] = i;
                    break;
                }                    
            }
        }
        return mark[0] == 0;
    }
};
