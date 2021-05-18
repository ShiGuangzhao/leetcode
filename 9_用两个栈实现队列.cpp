/*************************************************************************
    > File Name: 9_用两个栈实现队列.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 10时48分44秒
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class CQueue {
private:
    stack<int> stk;
    stack<int> stk_tmp;

    void swap_stk(stack<int> &s1, stack<int> &s2) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        stk.push(value);
    }
    
    int deleteHead() {
        if(stk.empty() && stk_tmp.empty()) {
            return -1;
        }
        if(stk_tmp.empty()) {
            swap_stk(stk, stk_tmp);
        }
        int ret = stk_tmp.top();
        stk_tmp.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(void) {
    auto q = new CQueue();
    cout << q->deleteHead() << endl;
    q->appendTail(1);
    q->appendTail(2);
    cout << q->deleteHead() << endl;
    q->appendTail(3);
    q->appendTail(4);
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;
}
