/*************************************************************************
    > File Name: 155_最小栈.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月21日 星期五 15时18分08秒
 ************************************************************************/

#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class MinStack {
private:
    list<int> valList;
    stack<list<int>::iterator> stk;

public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int val) {
        auto beg = valList.begin();
        while(beg != valList.end() and val > *beg) {
            ++beg;
        }
        stk.push(valList.insert(beg, val));
        // cout << "push" << valList.size() << " " << stk.size() << " " << *(stk.top())<< endl;
    }

    void pop() {
        valList.erase(stk.top());
        stk.pop();
        // cout << "pop" << valList.size() << " " << stk.size() << endl;
    }

    int top() {
        // cout << "top" << valList.size() << " " << stk.size() << endl;
        return *(stk.top());
    }

    int getMin() {
        if(valList.size() == 0) {
            throw std::exception();
        }
        return *(valList.begin());
    }
};
