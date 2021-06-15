/*************************************************************************
    > File Name: 152_最大乘积子数组.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月10日 星期六 11时37分12秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int maxSum(vector<int>::iterator beg, vector<int>::iterator end) {
        if(beg + 1 == end) {
            return *beg;
        }
        int left = 1, right = 1;
        while(beg != end && *beg > 0) {
            left *= *beg++;
        }
        if(beg == end) {
            return left;
        }
        while(--end != beg && *end > 0) {
            right *= *end;
        }
        if(beg == end)
            return std::max(left, right);
        left *= *beg++;
        right *= *end;
        auto ret = 1;
        while(beg < end) {
            ret *= *beg++;
        }
        return ret > 0? left * right * ret: ret * std::min(left, right);
    }
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        auto beg = nums.begin(), end = nums.end();
        int ret = *std::max_element(nums.begin(), nums.end());
        while(beg != end) {
            if(*beg == 0) {
                ++beg;
                continue;
            }
            auto tmp = beg + 1;
            while(tmp != end && *tmp != 0) {
                ++tmp;
            };
            ret = max(ret, maxSum(beg, tmp));
            beg = tmp;
        }
        return ret;
    }
        

    // 错误，不能处理-2， -2， 2， -3
    int maxProduct1(vector<int>& nums) {
        int left = 1;
        int ret = nums[0];
        for(auto x: nums) {
            if(x == 0) {
                left = 1;
                ret = std::max(ret, 0);
            }
            else {
                left *= x;
                ret = std::max(ret, left);
            }
        }
        return ret;
    }
};

int main(void) {
    vector<int> nums{7, -2, -3};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}
