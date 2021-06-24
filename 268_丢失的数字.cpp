/*************************************************************************
    > File Name: 268_丢失的数字.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月22日 星期二 13时20分09秒
 ************************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 使用map，O(n)空间复杂度
    int missingNumber1(vector<int>& nums) {
        vector<bool> numMap(nums.size() + 1, false); 
        for(auto i: nums) {
            numMap[i] = true;
        }
        auto ret = std::find(numMap.begin(), numMap.end(), false);
        return ret - numMap.begin();
    }
    
    // 交换
    // 最后放一个-1，-1的那位没有
    int missingNumber2(vector<int>& nums) {
        nums.push_back(-1);
        for(auto i = 0; i < nums.size() - 1; ++i) {
            while(nums[i] != i and nums[i] != -1) {
                std::swap(nums[i], nums[nums[i]]);
            }
        }
        for(auto i = 0; i < nums.size(); ++i) {
            if(nums[i] == -1) {
                return i;
            }
        }
        return nums.size() - 1;
    }

    // 异或
    int missingNumber(vector<int>& nums) {
        auto ret = nums.size();
        for(auto i: nums) {
            ret ^= i;
        }
        for(auto i = 0; i < nums.size(); ++i) {
            ret ^= i;
        }
        return ret;
    }
};
