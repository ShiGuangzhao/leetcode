/*************************************************************************
    > File Name: 155_最小栈.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月21日 星期五 15时18分08秒
 ************************************************************************/

#include <exception>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack {
private:
    // value, min
    stack<pair<int, int>> stk;

public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int val) {
        if(stk.empty()) {
            stk.push({val, val});
        }
        else {
            stk.push({val, std::min(val, stk.top().second)});
        }
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};
