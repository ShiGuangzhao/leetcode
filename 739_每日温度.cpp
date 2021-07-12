/*************************************************************************
    > File Name: 739_每日温度.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年07月10日 星期六 14时04分24秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力解法
    // 超出时间限制
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        for(auto i = 0; i < temperatures.size(); ++i) {
            for(auto j = i + 1; j < temperatures.size(); ++j) {
                if(temperatures[j] > temperatures[i]) {
                    ret[i] = j - i;
                    break;
                }
            }
        }
        return ret;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> dp(temperatures.size(), 0);
        for(int i = int(temperatures.size()) - 2; i >= 0; --i) {
            int j = i + 1;
            while(dp[j] != 0 and temperatures[j] <= temperatures[i]) {
                j = j + dp[j];
            }
            dp[i] = (temperatures[j] > temperatures[i])? j - i: 0;
        }
        return dp;
    }
};
