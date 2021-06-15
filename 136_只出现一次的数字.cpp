/*************************************************************************
    > File Name: 136_只出现一次的数字.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月20日 星期四 14时02分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 暴力解法，使用map记录
    // O(n)空间
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count; 
        for(auto i: nums) {
            ++count[i];
        }
        for(auto &p: count) {
            if(p.second == 1) {
                return p.first;
            }
        }
        return 0;
    }

    // 使用位运算，只用常数空间
    int singleNumber1(vector<int>& nums) {
        int ret = nums[0];
        for(auto i = 1; i < nums.size(); ++i) {
            ret ^= nums[i];
        }
        return ret;
    }

};
