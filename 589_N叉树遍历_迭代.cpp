/*************************************************************************
    > File Name: 589_N叉树遍历.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月22日 星期一 11时16分36秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:

    vector<int> preorder(Node* root) {
        vector<int> ret;
        stack<Node *> stk;
        Node *tmp;

        if(root != nullptr) {
            stk.push(root);
        }

        while(!stk.empty()) {
            tmp = stk.top();
            stk.pop();
            ret.push_back(tmp->val);
            for(auto it = tmp->children.rbegin(); it < tmp->children.rend(); ++it) {
                stk.push(*it);
            }
        }
        return ret;
    }
};
