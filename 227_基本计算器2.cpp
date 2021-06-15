/*************************************************************************
    > File Name: 227_基本计算器2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月11日 星期五 14时45分29秒
 ************************************************************************/

#include <cctype>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

class Solution {
private:
    inline void push(vector<int> &stk, int &num, char sym) {
        switch(sym) {
            case '+':   stk.push_back(num); break;
            case '-':   stk.push_back(-num); break;
            case '*':   stk.back() *= num; break;
            case '/':   stk.back() /= num; break;
            default:    throw std::invalid_argument("");
        }
        num = 0;
    }
public:
    int calculate(string s) {
        vector<int> stk;
        auto num = 0;
        auto lastSym = '+';
        for(auto c: s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c != ' ') {
                push(stk, num, lastSym);
                lastSym = c;
            }
        }
        push(stk, num, lastSym);
        return std::accumulate(stk.begin(), stk.end(), 0);
    }

    int calculate1(string s) {
        vector<int> stk;
        int left = 0, right = 0;
        while(s[left] == ' ')   ++left;
        stk.push_back(std::stoi(s.substr(left, s.size() - left)));
        while(++left < s.size() and std::isdigit(s[left])) {
        }
        while(s[left] == ' ') ++left;
        while(1) {
            // cout << s[left - 1] << endl;
            if(left >= s.size()) {
                return std::accumulate(stk.begin(), stk.end(), 0);
            }
            right = ++left;     // 第一个数字
            while(++right < s.size() and std::isdigit(s[right])) {
                // 数字结束后的符号
            }
            while(s[right] == ' ') ++right;
            auto numStr = s.substr(left, right - left);
            auto num = std::stoi(numStr);
            push(stk, num, s[left - 1]);
            left = right;
            // cout << "end " << stk.back() << endl;
        }
        return std::accumulate(stk.begin(), stk.end(), 0);
    }
};

int main(void) {
    Solution s;
    // cout << std::stoi(" 2 3") << endl;
    cout << s.calculate("2147483647") << endl;
    // cout << s.calculate("3 + 2 * 5 + 2 / 1") << endl;
}
