/*************************************************************************
    > File Name: 328_奇偶链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月28日 星期一 21时32分39秒
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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        auto pOddHead = head;
        auto pEvenHead = head->next;
        auto pOddLast = pOddHead;
        auto pEvenLast = pEvenHead;
        head = head->next->next;
        while(head != nullptr) {
            pOddLast->next = head;
            pOddLast = pOddLast->next;
            head = head->next;
            pEvenLast->next = head;
            pEvenLast = pEvenLast->next;
            if(head == nullptr) {
                break;
            }
            head = head->next;
        }
        pOddLast->next = pEvenHead;
        return pOddHead;
    }
};
