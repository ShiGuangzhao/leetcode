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
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        auto s1 = nums1.size();
        auto s2 = nums2.size();
        size_t i1 = 0, i2 = 0;
        if(s1 == 0 && s2 == 0) {
            return 0;
        }
        while(1) {
            if(i1 == s1 || i2 == s2) {
                break;
            }
            if(nums1[i1] < nums2[i2]) {
                temp.push_back(nums1[i1++]);
            }
            else {
                temp.push_back(nums2[i2++]);
            }
        }
        if(i2 == s2) {
            temp.insert(temp.end(), nums1.begin() + i1, nums1.end());
        }
        else if(i1 == s1) {
            temp.insert(temp.end(), nums2.begin() + i2, nums2.end());
        }
        else {
            if(nums1[0] < nums2[0]) {
                temp.insert(temp.end(), nums1.begin(), nums1.end());
                temp.insert(temp.end(), nums2.begin(), nums2.end());
            }
            else {
                temp.insert(temp.end(), nums1.begin(), nums1.end());
                temp.insert(temp.end(), nums2.begin(), nums2.end());
            }
        }
        auto n = temp.size();
        if(n % 2 == 0) {
            auto a = temp[n / 2];
            auto b = temp[(n / 2) - 1];
            return (double)(a + b) / 2;
        }
        else {
            return temp[n / 2];
        }
    }
};

