/*************************************************************************
    > File Name: 169_多数元素.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月28日 星期五 16时30分52秒
 ************************************************************************/

#include <exception>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    // 使用map计数，时间O(n)，空间O(n)
    int majorityElement_map(vector<int>& nums) {
        auto half = nums.size() / 2;
        unordered_map<int, int> count;
        for(auto i: nums) {
            ++count[i];
            if(count[i] > half) {
                return i;
            }
        }
        throw std::exception();
    }

    // 排序，复杂度取决于排序
    int majorityElement(vector<int>& nums) {
        // if(nums.size() < 3) {
            // return nums[0];
        // }
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        
    }
};
