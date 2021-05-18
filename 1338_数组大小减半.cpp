/*************************************************************************
    > File Name: 1338_数组大小减半.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月08日 星期四 19时31分53秒
 ************************************************************************/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

class Solution {
public:
    // 实际上就是要统计每个数字出现了多少次
    // 然后找到最大的几个，使他们和大于一半数组大小
    int minSetSize(vector<int>& arr) {
        map<int, int> count;
        for(int i: arr) {
            if(count.find(i) != count.end()) {
                ++count[i];
            }
            else {
                count[i] = 1;
            }
        }
        vector<pair<int, int>> vec;
        for(auto &it: count) {
            cout << it.first << ": " << it.second << endl;
            vec.push_back(it);
        }
        std::sort(vec.begin(), vec.end(),
                [](pair<int, int> a, pair<int, int> b) {
                    return a.second > b.second;
                });
        
        int maxCount = 0; 
        int stop = arr.size() / 2;
        int ret = 0;
        for(auto it: vec) {
            maxCount += it.second;
            ++ret;
            if(maxCount >= stop) {
                break;
            }
        }

        // 超出时间限制
        // while(maxCount < stop) {
            // // cout << maxCount << endl;
            // auto it = std::max_element(count.begin(), count.end(), 
                    // [](pair<int, int> a, pair<int, int> b) {
                        // return a.second < b.second;
                    // });
            // maxCount += (*it).second;
            // (*it).second = 0;
            // ++ret;
        // }
        return ret;
    }

    // 思路一样的简化版本
    int minSetSize2(vector<int>& arr) {
        map<int, int> count;
        for(int i: arr) {
            ++count[i];
        }
        vector<int> vec;
        for(auto &it: count) {
            vec.push_back(it.second);
        }
        std::sort(vec.begin(), vec.end(), std::greater<int>());
        
        int maxCount = 0; 
        int stop = arr.size() / 2;
        int ret = 0;
        for(auto it: vec) {
            maxCount += it;
            ++ret;
            if(maxCount >= stop) {
                break;
            }
        }
        return ret;
    }
};

int main(void) {
    vector<int> v{1, 2, 3, 3, 5, 6, 6, 8, 9, 10};
    Solution s;
    cout << s.minSetSize(v) << endl;
}
