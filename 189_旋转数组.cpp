/*************************************************************************
    > File Name: 189_旋转数组.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月06日 星期日 19时54分34秒
 ************************************************************************/

#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    inline void swap_array(vector<int> &nums, int beg1, int beg2, int k) {
        // cout << "swap: " << beg1 << " " << beg2 << " " << k << endl;
        // cout << "swap0: " << nums[0];
        while(k-- > 0) {
            std::swap(nums[beg1++], nums[beg2++]);
        }
        // cout << " " << nums[0] << endl;
    }

    // 不包含end
    void rotate_Iter(vector<int> &nums, int beg, int end, int k) {
        k = k % (end - beg);
        // cout << beg << " " << end << " " << k << endl;
        if(k == 0) {
            return;
        }

        if(2 * k <= end - beg) {
            swap_array(nums, beg, beg + k, k);
            rotate_Iter(nums, beg + k, end, k);
        }
        else {
            auto tmp = end - beg - k;
            swap_array(nums, end - 2 * tmp, end - tmp, tmp);
            k %= tmp;
            rotate_Iter(nums, beg, end - tmp, k);
        }
    }

public:
    // 假设k不大于数组长度
    // 直接复制，时间空间O(N)
    void rotate1(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> ret(nums.end() - k, nums.end());
        for(auto i = 0; i < nums.size() - k; ++i) {
            ret.push_back(nums[i]);
        }
        nums = ret;
    }

    void rotate2(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tmp(nums.begin(), nums.end() - k);
        auto beg = nums.begin();
        for(auto it = nums.end() - k; it != nums.end(); ++it) {
            *beg++ = *it;
        }
        for(auto i: tmp) {
            *beg++ = i;
        }
    }

    // 递归方法，参考189.ora
    // 错的
    void rotate(vector<int>& nums, int k) {
        k = nums.size() - (k % nums.size());
        rotate_Iter(nums, 0, nums.size(), k);
    }
};
