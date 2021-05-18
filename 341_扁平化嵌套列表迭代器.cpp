/*************************************************************************
    > File Name: 341_扁平化嵌套列表迭代器.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月23日 星期二 10时33分19秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> itStk;
    stack<vector<NestedInteger>::iterator> endStk;
    bool hasNextValue = true;

    void setToNext(void) {
        ++(itStk.top());
        while(itStk.top() == endStk.top()) {
            itStk.pop();
            endStk.pop();
            if(!itStk.empty()) {
                ++(itStk.top());
            }
            else {
                break;
            }
        }
        if(itStk.empty()) {
            hasNextValue = false;
        }
        else{
            while(!(*itStk.top()).isInteger()){
                vector<NestedInteger> &list = (*itStk.top()).getList();
                if(list.empty()) {
                    setToNext();
                    break;
                } 
                else {
                    itStk.push(list.begin());
                    endStk.push(list.end());
                }
            }
        }

    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(nestedList.empty()) {
            hasNextValue = false;
        }
        else {
            itStk.push(nestedList.begin());
            endStk.push(nestedList.end());
            while(!(*itStk.top()).isInteger()){
                vector<NestedInteger> &list = (*itStk.top()).getList();
                if(list.empty()) {
                    setToNext();
                    break;
                }
                else {
                    itStk.push(list.begin());
                    endStk.push(list.end());
                }
            }
        }
    }

    // 如果下一个元素为列表，则迭代器入栈
    int next() {
        int ret;
        ret = (*itStk.top()).getInteger();
        cout << "next: " << ret << endl;
        setToNext();
        return ret;
    }

    bool hasNext() {
        return hasNextValue;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
