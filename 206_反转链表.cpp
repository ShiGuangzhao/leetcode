/*************************************************************************
    > File Name: 206_反转链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月07日 星期一 00时07分30秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode *last;
    ListNode* reverseList_Iter(ListNode* head) {
        // 保证head不为空
        if(head->next == nullptr) {
            last = head;
        }
        else {
            auto nextNode = reverseList_Iter(head->next);
            nextNode->next = head;
        }
        return head;
    }

public:
    // 循环
    ListNode* reverseList1(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode *ret = nullptr;
        while(head->next != nullptr) {
            auto tmp = head->next;
            head->next = ret;
            ret = head;
            head = tmp;
        }
        head->next = ret;
        return head;
    }

    // 递归
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        reverseList_Iter(head);
        head->next = nullptr;
        return last;
    }
};
