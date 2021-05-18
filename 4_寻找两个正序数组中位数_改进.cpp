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
    struct Rember {
        int num;
        int num_1;
        void push_back(int n) {
            num_1 = num;
            num = n;
        }
        double result(void) {
            return ((double)num + num_1) / 2;
        }
    };

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        auto s1 = nums1.size();
        auto s2 = nums2.size();
        size_t i1 = 0, i2 = 0;
        if(s1 == 0 && s2 == 0) {
            return 0;
        }
        auto n = s1 + s2;
        auto stop = n / 2;
        auto count = 0;
        if(n % 2 == 0) {
            Rember temp;
            while(count++ <= stop) {
                if(i2 == s2 || nums1[i1] < nums2[i2]) {
                    temp.push_back(nums1[i1++]);
                }
                else {
                    temp.push_back(nums2[i2++]);
                }
            }
            return temp.result();
        }
        else {
            int temp;
            while(count++ <= stop) {
                if(i1 == s1 || nums1[i1] < nums2[i2]) {
                    temp = nums1[i1++];
                }
                else {
                    temp = nums2[i2++];
                }
            }
            return temp;
        }
    }
};

int main(void) {
    Solution s;
    vector<int> a{0, 0}, b{0, 0}; 
    cout << s.findMedianSortedArrays(a, b) << endl;
}
