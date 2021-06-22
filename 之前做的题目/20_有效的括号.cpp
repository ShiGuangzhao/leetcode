/*************************************************************************
    > File Name: 20_有效的括号.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月21日 星期五 10时13分16秒
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    stk.push(c);
                    break;
                case ')':
                    if(stk.empty() || stk.top() != '(') return false;
                    stk.pop();
                    break;
                case '}':
                    if(stk.empty() || stk.top() != '{') return false;
                    stk.pop();
                    break;
                case ']':
                    if(stk.empty() || stk.top() != '[') return false;
                    stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};
