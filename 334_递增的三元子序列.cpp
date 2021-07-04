/*************************************************************************
    > File Name: 334_递增的三元子序列.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月28日 星期一 22时03分24秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 抄的
    bool increasingTriplet(vector<int>& nums) {
        int small = INT32_MAX, middle = INT32_MAX;
        for(auto n: nums) {
            if(n <= small)          small = n;
            else if(n <= middle)    middle = n;
            else                    return true;
        }
        return false;
    }

    // 维护最大值(int)和最小值(vector)
    // 时间空间O(n)
    bool increasingTriplet2(vector<int>& nums) {
        vector<int> minNum(nums.size());
        int maxNum = nums.back();
        minNum[0] = nums[0];
        for(auto i = 1; i < nums.size(); ++i) {
            minNum[i] = std::min(nums[i], minNum[i - 1]);
        }
        for(int j = int(nums.size()) - 2; j > 0; --j) {
            if(nums[j] < maxNum and nums[j] > minNum[j]) {
                return true;
            }
            maxNum = std::max(maxNum, nums[j]);
        }
        return false;
    }

    // 暴力解：超出时间限制
    bool increasingTriplet1(vector<int>& nums) {
        for(auto i = 0; i < nums.size(); ++i) {
            for(auto j = i + 1; j < nums.size(); ++j) {
                if(nums[i] < nums[j]) {
                    for(auto k = j + 1; k < nums.size(); ++k) {
                        if(nums[j] < nums[k]) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
