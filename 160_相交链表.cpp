/*************************************************************************
    > File Name: 160_相交链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月21日 星期五 16时14分57秒
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
    // 使用一个集合记录其中一个链表的节点
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if(headA == nullptr or headB == nullptr) {
            return nullptr;
        }
        unordered_set<ListNode *> nodes;
        while(headA != nullptr) {
            nodes.insert(headA);
            headA = headA->next;
        }
        while(headB != nullptr) {
            if(nodes.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }

    // 修改第一个链表
    // 题目中不能修改
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if(headA == nullptr or headB == nullptr) {
            return nullptr;
        }
        auto mark = new ListNode(0);
        while(headA != nullptr) {
            auto tmp = headA;
            headA = headA->next;
            tmp->next = mark;
        }
        while(headB != nullptr) {
            if(headB->next == mark) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }

    // 双指针
    // 目前还有错
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr or headB == nullptr) {
            return nullptr;
        }
        auto pA = headA;
        auto pB = headB;
        while(pA != pB) {
            if(pA == nullptr)   pA = headB;
            if(pB == nullptr)   pB = headA;
            if(pA == pB)        return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
