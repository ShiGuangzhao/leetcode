/*************************************************************************
    > File Name: 4_寻找两个正序数组中位数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月15日 星期一 19时20分02秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    inline double getHalf(vector<int> &nums, size_t s) {
        if(s % 2 == 0) {
            return (double)(nums[s/2] + nums[s/2 - 1]) / 2;
        }
        else {
            return nums[s/2];
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        auto s1 = nums1.size();
        auto s2 = nums2.size();
        if(s1 == 0 && s2 == 0) {
            return 0;
        }
        if(s2 == 0) {
            return getHalf(nums1, s1);
        }
        else if(s1 == 0) {
            return getHalf(nums2, s2);
        }
        auto n = s1 + s2;
        auto stop = n / 2;
        decltype(stop) count = 0;

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        cout << *it1 << *it2 << endl;
        while(count++ <= stop) {
            if(it2 == nums2.end() || (it1 != nums1.end() && *it1 < *it2)) {
                ++it1;
            }
            else {
                ++it2;
            }
            // cout << "before: " << *it1 << *it2 << endl;
        }
        --it1;  --it2;
        cout << *it1 << *it2 << endl;
        // if(it1 == nums1.end())  --it1;
        // if(it2 == nums2.end())  --it2;

        if(n % 2 == 0) {
            double a = 0, b = 0;
            // cout << *it1 << *it2 << endl;
            if(*it1 > *it2) {
                a = *it1;
                b = (it1 == nums1.begin()) ? *it2: max(*(--it1), *it2);
                // cout << "ab: " << a << b << endl;
                return (a + b) / 2;
            }
            else {
                a = *it2;
                b = (it2 == nums2.begin()) ? *it1: max(*(--it2), *it1);
                // cout << "ab2: " << a << b << endl;
                return (a + b) / 2;
            }

        }
        else {
            return *it1 > *it2? *it1: *it2;
        }
    }
};

int main(void) {
    Solution s;
    vector<int> a{3}, b{-2, -1}; 
    cout << s.findMedianSortedArrays(a, b) << endl;
}
