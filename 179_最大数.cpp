/*************************************************************************
    > File Name: 179_最大数.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月01日 星期二 15时33分03秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    // a < b 时返回 true
    class compare {
    private:
        bool cmp(string::iterator aBeg, string::iterator aEnd, \
                string::iterator bBeg, string::iterator bEnd) {
            auto ait = aBeg;
            auto bit = bBeg;
            while(ait != aEnd and bit != bEnd) {
                if(*ait != *bit) {
                    return *ait < *bit;
                }
                ++ait;
                ++bit;
            }
            if(ait == aEnd and bit == bEnd) {
                return true;
            }
            return (ait == aEnd)? cmp(aBeg, aEnd, bit, bEnd): cmp(ait, aEnd, bBeg, bEnd);
        }

    public:
        bool operator() (string a, string b) {
            return cmp(a.begin(), a.end(), b.begin(), b.end());
        }
    };

public:
    string largestNumber(vector<int>& nums) {
        // 第一位大的先入字符串
        // 不同位的，第一位一样大则按顺序比较
        // 如果前面的都一样，如果最后一位大于第一位则大
        std::priority_queue<string, vector<string>, compare> heap;
        for(auto i: nums) {
            auto s = std::to_string(i);
            heap.push(s);
        }
        string ret;
        if(!heap.empty() and heap.top().front() == '0') {
            return string("0");
        }
        while(!heap.empty()) {
            ret += heap.top();
            heap.pop();
        }
        return ret;
    }
};
