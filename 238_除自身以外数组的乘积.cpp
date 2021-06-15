/*************************************************************************
    > File Name: 238_除自身以外数组的乘积.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月15日 星期二 18时45分35秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力解法
    // 超出时间限制
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        for(auto i = 0; i < nums.size(); ++i) {
            for(auto j = 0; j < nums.size(); ++j) {
                if(i != j) {
                    ret[i] *= nums[j];
                }
            }
        }
        return ret;
    }

    // 动态规划
    // 使用两个数组来维护左右计算结果
    vector<int> productExceptSelf2(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        if(nums.size() == 0)    return ret;

        left[0] = nums[0];
        for(auto i = 1; i < nums.size(); ++i) {
            left[i] = left[i - 1] * nums[i];
            ret[i] = left[i - 1];
        }
        right.back() = nums.back();
        for(int i = nums.size() - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i];
            ret[i] *= right[i + 1];
        }
        return ret;
    }

    // 动态规划优化
    // 使用两个数组来维护左右计算结果
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);

        if(nums.size() == 0)    return ret;

        ret[0] = 1;
        for(auto i = 0; i < nums.size() - 1; ++i) {
            ret[i + 1] = ret[i] * nums[i];
        }
        auto tmp = nums.back();
        for(int i = nums.size() - 2; i >= 0; --i) {
            ret[i] *= tmp;;
            tmp *= nums[i];
        }
        return ret;
    }
};
