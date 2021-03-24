/*************************************************************************
    > File Name: 234_回文链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月17日 星期三 19时17分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == nullptr) {
            return head;
        }
        ListNode *pLast = nullptr, *pLeft = head, *pNext = nullptr;
        if(left != 1) {
            pLast = head;
            for(auto i = 2; i < left; ++i) {
                pLast = pLast->next;
            }
            pLeft = pLast->next;
        }
        pNext = pLeft;
        for(auto i = left; i <= right; ++i) {
            pNext = pNext->next;
        }
        auto pOralNext = pNext;
        while(pLeft != pOralNext) {
            auto temp = pLeft;
            pLeft = pLeft->next;
            temp->next = pNext;
            pNext = temp;
        };
        
        if(pLast) {
            pLast->next = pNext;
            return head;
        }
        else {
            return pNext;
        }
    }
};

int main(void) {
    auto head = new ListNode(1);
    auto head1 = new ListNode(2);
    head->next = head1;
    // auto head2 = new ListNode(2);
    // head1->next = head2;
    // auto head3 = new ListNode(1);
    // head2->next = head3;
    Solution s;
    s.reverseBetween(head, 1,2);
    // auto v = s.isPalindrome(head);
    // cout << v <<endl;
}
