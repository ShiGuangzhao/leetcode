/*************************************************************************
    > File Name: 134_加油站.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月19日 星期三 16时01分19秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
    bool canCompleteI(vector<int>& gas, int i) {
        // 不考虑整数溢出
        int left;
        left = gas[i];
        for(auto s = i + 1; s < gas.size(); ++s) {
            left += gas[s];
            if(left < 0)    return false;
        }
        for(auto s = 0; s < i; ++s) {
            left += gas[s];
            if(left < 0)    return false;
        }
        return true;
    }

public:
    // 从i开始，gas[i] > cost[i]
    // 对于i: i-1，应满足sum[gas] > sum(cost)
    // 暴力求解
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 优化，先减再算
        for(int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }
        for(int i = 0; i < gas.size(); ++i) {
            if(gas[i] >= 0 and canCompleteI(gas, i)) {
                return i;
            }
        }
        return -1;
    }

    // 优化，相邻同符号可以合并
    // 最后一个数为负，肯定不对
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        // 优化，合并相同符号
        vector<pair<int, int>> mergeVec;    // {index, gas}
        mergeVec.push_back({0, gas[0] - cost[0]});
        for(int i = 1; i < gas.size(); ++i) {
            int tmpGas = gas[i] - cost[i];
            if((tmpGas ^ mergeVec.back().second) >= 0        // 判断两个数符号相同
                    or mergeVec.back().second > tmpGas) {   // 剩余gas为正
                mergeVec.back().second += tmpGas;
            }
            else {
                mergeVec.push_back({i, tmpGas});
            }
        }
        if(mergeVec.back().second < 0) {
            return -1;
        }
        int sum = mergeVec.back().second;
        for(int i = 0; i < mergeVec.size() - 1; ++i) {
            sum += mergeVec[i].second;
            if(sum < 0) {
                return -1;
            }
        }

        return mergeVec.back().first;
    }
};
