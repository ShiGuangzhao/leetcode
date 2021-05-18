/*************************************************************************
    > File Name: 138_复制带随机指针的链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年04月06日 星期二 19时10分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }

        map<Node *, Node *> addrMap{{nullptr, nullptr}};
        auto newHead = new Node(head->val);
        addrMap[head] = newHead;

        auto newIt = newHead;
        auto oldIt = head->next;
        while(oldIt != nullptr) {
            newIt->next = new Node(oldIt->val);
            newIt = newIt->next;
            addrMap[oldIt] = newIt;
            oldIt = oldIt->next;
        }
        oldIt = head;
        newIt = newHead;
        while(oldIt != nullptr) {
            newIt->random = addrMap[oldIt->random];
            oldIt = oldIt->next;
            newIt = newIt->next;
        }
        return newHead;
    }
};
