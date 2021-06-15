/*************************************************************************
    > File Name: 150_逆波兰表达式.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月12日 星期一 11时05分17秒
 ************************************************************************/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    // 逆波兰表达式求解
    // 遇到数字则入栈，遇到运算符则取栈顶两个数
    // 压入运算结果
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        set<string> symbol{"+", "-", "*", "/"};
        for(auto &s: tokens) {
            if(symbol.find(s) == symbol.end()) {    // 数字
                stk.push(std::stoi(s));
            }
            else {
                auto tmp = stk.top();
                stk.pop();
                switch(s[0]) {
                    case '+':
                        stk.top() += tmp;   break;
                    case '-':
                        stk.top() -= tmp;   break;
                    case '*':
                        stk.top() *= tmp;   break;
                    case '/':
                        stk.top() /= tmp;   break;
                    default:
                        throw std::invalid_argument("evalRPN 输入错误");
                }
            }
        }
        return stk.top();      
    }
};
