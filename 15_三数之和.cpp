/*************************************************************************
    > File Name: 15_三数之和.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月14日 星期三 18时35分29秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    // b、c搜索使用双指针
    vector<vector<int>> threeSum2(vector<int>& nums) {
        auto n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(auto a = 0; a < n; ++a) {
            if(a > 0 and nums[a] == nums[a - 1]) {
                continue;
            }
            auto target = -nums[a];
            auto c = n - 1;
            for(auto b = a + 1; b < n; ++b) {
                if(b > a + 1 and nums[b] == nums[b - 1]) {
                    continue;
                }
                while(b < c and nums[b] + nums[c] > target) {
                    --c;
                }
                if(b == c) {
                    break;
                }
                if(nums[b] + nums[c] > target) {
                    ret.push_back({nums[a], nums[b], nums[c]});
                }

            }
        }
        return ret;
    }

    // 超出时间限制: N^3
    // a = 1: n, b = a: n, c = b: n
    // 如果b + c = -a，则入队
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        set<pair<int, int>> retSet;    // 标志位

        for(auto a = nums.begin(); a != nums.end(); ++a) {
            for(auto b = a + 1; b != nums.end(); ++b) {
                for(auto c = b + 1; c != nums.end(); ++c) {
                    if(*a + *b + *c == 0) {
                        if(retSet.find({*a, *b}) != retSet.end()) {
                            continue;
                        }
                        ret.push_back({*a, *b, *c});
                        retSet.insert({*b, *c});
                    }
                }
            }
        }
        return ret;
    }

    // 超出时间限制: N^3
    // 排序后查找
    // 三种情况：元素只有一个，元素有两个，元素大于等于三个
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        auto it = nums.begin();
        while(it != nums.end()) {
            if(*it * *(nums.end() - 1) > 0) {
                return ret;
            }
            auto count = 1;
            auto next = it + 1;
            while(next != nums.end() and *it == *next) {
                ++count;
                ++next;
            }
            if(*it == 0 and count >= 3) {
                ret.emplace_back(3, 0);
            }
            if(count >= 2) {
                auto tmp = std::find(next, nums.end(), -(*it) * 2);
                if(tmp != nums.end()) {
                    ret.push_back({*it, *it, *tmp});
                }
            }
            twoSum(next, nums.end(), *it, ret);
            it = next;
        }
        return ret;
    }
private:
    void twoSum(vector<int>::iterator beg, vector<int>::iterator end, int a, vector<vector<int>> &ret) {
        while(beg != end) {
            // cout << "1" << endl;
            auto count = 1;
            auto next = beg + 1;
            while(next != end and *next == *beg) {
                ++next;
                ++count;
            }
            if(count >= 2) {
                if(*beg + *beg + a == 0) {
                    ret.push_back({a, *beg, *beg});
                }
            }
            auto tmp = std::find(next, end, -(a + *beg));
            if(tmp != end) {
                ret.push_back({a, *beg, *tmp});
            }
            beg = next;
        }
    }

};

int main(void) {
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution s;
    s.threeSum1(nums);
}
