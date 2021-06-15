/*************************************************************************
    > File Name: 14_最长公共前缀.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月11日 星期四 10时43分39秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty() || strs[0].empty()) {
            return string("");
        }
        vector<decltype(strs.at(0).begin())> iter;
        auto len = strs.size();
        for(auto i = 0; i < len; ++i) {
            iter.push_back(strs[i].begin());
        }
        auto itend = strs.at(0).end();
        for(; iter[0] != itend; ++iter[0]) {
            for(auto i = 1; i < len; ++i) {
                if(*(iter[0]) != *(iter[i])) {
                    return string(strs[0].begin(), iter[0]);
                }
                ++iter[i];
            }
        }
        return string(strs[0]);
    }
};

int main(void) {
    Solution s;
    vector<string> strs = {
        "asdg", "asewr", "ascdevr"
    };
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
