/*************************************************************************
    > File Name: 131_分割回文串.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月19日 星期三 13时36分40秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void setPartition(vector<vector<string>> &ret, vector<string> &parts,
            vector<vector<int>> &partIndex, string &s, int i) {
        if(i == s.size()) {
            ret.push_back(parts);
            return;
        }
        for(auto end: partIndex[i]) {
            parts.push_back(s.substr(i, end - i));
            setPartition(ret, parts, partIndex, s, end);
            parts.pop_back();
        }
    }
public:
    // 从后往前计算
    // 动态规划
    // 使用一个数组标记该位置到为回文串的下一个位置
    vector<vector<string>> partition(string s) {
        vector<vector<int>> partIndex(s.size(), vector<int>{});
        partIndex[s.size() - 1].push_back(s.size());
        // 动态规划寻找回文串
        for(int i = s.size() - 2; i >= 0; --i) {
            partIndex[i].push_back(i + 1);
            if(s[i] == s[i+1]) {
                partIndex[i].push_back(i + 2);
            }
            for(auto end: partIndex[i + 1]) {
                if(end < s.size() and s[i] == s[end]) {
                    partIndex[i].push_back(end + 1);
                }
            }
        }
        // 递归记录返回值
        vector<vector<string>> ret;
        vector<string> parts;
        setPartition(ret, parts, partIndex, s, 0);

        return ret;
    }
};

int main(void) {
    Solution s;
    s.partition("aab");
}
