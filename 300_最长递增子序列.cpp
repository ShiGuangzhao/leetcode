#include <iostream>

class Solution {
public:
    // O(n2)时间复杂度
    // 动态规划
    int lengthOfLIS(vector<int>& nums) {
        vector<int> count(nums.size(), 1);
        for(int i = nums.size() - 2; i >= 0; --i) {
            for(auto j = i + 1; j < nums.size(); ++j) {
                if(nums[j] > nums[i] and count[i] <= count[j]) {
                    count[i] = count[j] + 1;
                }
            }
        }
        return *std::max_element(count.begin(), count.end());
    }
};
