/*************************************************************************
    > File Name: 13_罗马数字转整数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月10日 18:57:12
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
    std::map<char, int> RomaValue{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int ret = 0;
        auto len = s.size();
        auto i = len;
        for(i = 0; i < len - 1; ++i) {
            if(RomaValue[s[i]] > RomaValue[s[i+1]]) {
                ret += RomaValue[s[i]]; 
            }
            else {
                ret -= RomaValue[s[i]];                 
                ret += RomaValue[s[i+1]];                 
                ++i;
            }
        }
        if(i < len) {
            ret += RomaValue[s[i]]; 
        }
        return ret;
    }
};


int main(void) {
    string s{"XII"};
    Solution sol;
    cout << sol.romanToInt(s) << endl;
    return 0;
}