/*************************************************************************
    > File Name: 682_棒球比赛.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 13时13分52秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for(auto it = ops.begin(); it < ops.end(); ++it) {
            if(*it == "+") {
                int tmp = stk.top();
                stk.pop();
                stk.push(tmp);
                int next = stk.top() + tmp;
                stk.push(next);
            }
            else if(*it == "D") {
                stk.push(stk.top() * 2);
            }
            else if(*it == "C") {
                stk.pop();
            }
            else {
                stk.push(stoi(*it));
            }
        }
        int sum;
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};

int main(void) {
    vector<string> ops = {
        "5", "2", "C", "D", "+"
    };
    Solution s;
    cout << s.calPoints(ops) << endl;
}
