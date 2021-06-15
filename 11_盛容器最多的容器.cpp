/*************************************************************************
    > File Name: 11_盛容器最多的容器.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月13日 星期二 19时38分35秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    inline int clac(vector<int>& height, int &i, int &j) {
        return std::min(height[i], height[j]) * (j - i);
    }
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        vector<int> left{0}, right{int(height.size()) - 1};
        for(auto i = 1; i < height.size(); ++i) {
            if(height[i] > height[left.back()]) {
                left.push_back(i);
                // cout << "left " << height[left.back()] << endl;
            }
        }
        for(int j = height.size() - 2; j > 0; --j) {
            if(height[j] > height[right.back()]) {
                right.push_back(j);
                // cout << "right " << height[right.back()] << endl;
            }
        }
        for(auto i: left) {
            for(auto j: right) {
                if(i >= j) {
                    break;
                }
                result = std::max(result, clac(height, i, j));
            }
        }
        return result;
    }

    // 双指针法
    int maxArea1(vector<int>& height) {
        int result = 0;
        auto left = height.begin();
        auto right = height.end() - 1;
        while(left < right) {
            if(*left < *right) {
                result = std::max(result, (*left) * int(right - left));
                // cout << "left " << result << endl;
                auto tmp = left;
                while(*tmp <= *left) {
                    ++tmp;
                    if(tmp == height.end()) {
                        return result;
                    }
                }
                left = tmp;
            }
            else {
                result = std::max(result, (*right) * int(right - left));
                // cout << "right " << result << endl;
                auto tmp = right;
                while(*tmp <= *right) {
                    --tmp;
                    if(tmp == height.begin()) {
                        return result;
                    }
                }
                right = tmp;
            }
        }
        return result;
    }

};

int main(void) {
    vector<int> v{2,3,4,5,18,17,6};
    Solution s;
    cout << s.maxArea1(v) << endl;
}
