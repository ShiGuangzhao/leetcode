/*************************************************************************
    > File Name: 1021_删除最外层括号.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月23日 星期二 13时57分27秒
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<int> stk;
        if(S.empty()) {
            return S;
        }
        for(int i = S.size() - 1; i >= 0; --i) {
            if(S[i] == ')') {
                if(stk.empty())
                    S.erase(S.begin() + i);
                stk.push(0);
            }
            else {
                stk.pop();
            }
            // cout << i << endl;
            if(stk.empty())
                S.erase(S.begin() + i);
        }
        return S;
    }
};

int main(void) {
    string s{"(())"};
    Solution sol;
    cout << sol.removeOuterParentheses(s) << endl;
}
