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
        // stack<int> stk;
        vector<int> stk;
        for(auto it = ops.begin(); it < ops.end(); ++it) {
            auto theEnd = stk.end();
            if(*it == "+") {
                auto tmp = *(theEnd - 2) + *(theEnd - 1);
                stk.push_back(tmp);
            }
            else if(*it == "D") {
                auto tmp = *(theEnd - 1) * 2;
                stk.push_back(tmp);
            }
            else if(*it == "C") {
                stk.pop_back();
            }
            else {
                stk.push_back(stoi(*it));
            }

        }
        return std::accumulate(stk.begin(), stk.end(), 0);
    }
};

int main(void) {
    vector<string> ops = {
        "5", "2", "C", "D", "+"
    };
    Solution s;
    cout << s.calPoints(ops) << endl;
}
