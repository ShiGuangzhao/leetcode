/*************************************************************************
    > File Name: 287_寻找重复数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月24日 星期四 12时31分39秒
 ************************************************************************/

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力搜索
    // 超出时间限制
    int findDuplicate1(vector<int>& nums) {
        for(auto i = 0; i < nums.size(); ++i) {
            for(auto j = i + 1; j < nums.size(); ++j) {
                if(nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        throw std::invalid_argument("没有重复数字");
    }

    // 把对应位置变成负数
    int findDuplicate2(vector<int>& nums) {
        auto ret = 0;
        for(auto i = 0; i < nums.size(); ++i) {
            ret = std::abs(nums[i]);
            if(nums[ret] < 0)   break;
            nums[ret] = -nums[ret];
        }
        for(auto &n: nums) {
            n = std::abs(n);
        }
        return ret;
    }

    // 快慢指针寻找数组的环
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast != slow);
        slow = 0;
        while(slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
