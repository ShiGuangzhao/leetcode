/*************************************************************************
    > File Name: 141_环形链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月19日 星期三 17时16分57秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 使用一个set记录地址
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> addr;
        while(head) {
            addr.insert(head);
            if(addr.find(head->next) != addr.end()) {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    // 优化，把遍历过的点指向一个特殊地址
    // 使用常量空间
    bool hasCycle1(ListNode *head) {
        auto p = head;
        while(head) {
            if(head->next == p) {
                return true;
            }
            else {
                auto tmp = head->next;
                head->next = p;
                head = tmp;
            }
        }
        return false;
    }
};
