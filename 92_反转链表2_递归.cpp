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
private:
    ListNode *pLast = nullptr;
    ListNode *pNext = nullptr;
    ListNode *pLeft = nullptr;
    ListNode *pRight = nullptr;
    int count = 1;

    ListNode *StepReverse(ListNode *head, const int left, const int right) {
        if(count == left - 1) {
            pLast = head;
        } else if(count == left) {
            pLeft = head;
        } else if(count == right) {
            pRight = head;
            pNext = head->next;
            return head;;
        }
        ++count;
        ListNode *thisNext = StepReverse(head->next, left, right);
        --count;
        if(count >= left) {
            thisNext->next = head;
        }
        return head;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == nullptr) {
            return head;
        }
        StepReverse(head, left, right);
        pLeft->next = pNext;
        if(pLast) {
            pLast->next = pRight;
            return head;
        } else {
            return pRight;
        }
    }
};

int main(void) {
    auto head = new ListNode(1);
    auto head1 = new ListNode(2);
    head->next = head1;
    // auto head2 = new ListNode(3);
    // head1->next = head2;
    // auto head3 = new ListNode(4);
    // head2->next = head3;
    Solution s;
    s.reverseBetween(head, 1, 2);
    // auto v = s.isPalindrome(head);
    // cout << v <<endl;
}
