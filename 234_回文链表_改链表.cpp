/*************************************************************************
    > File Name: 234_回文链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月17日 星期三 19时17分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <array>
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        auto pHead = head;
        size_t size = 0;
        while(head) {
            ++size;
            head = head->next;
        }
        auto stop = size / 2;
        head = pHead;

        auto count = 1;
        auto pLast = head, temp = head;
        head = head->next;
        while(count < stop) {
            temp = head;
            head = head->next;
            temp->next = pLast;
            pLast = temp;
            ++count;
        }
        auto pMid = head;
        if(size % 2 != 0) {
            head = head->next;
        }

        bool ret = true;
        temp = pLast;
        while(head) {
            if(temp->val != head->val) {
                ret = false;
                break;
            }
            head = head->next;
            temp = temp->next;
        }
        count = 1;
        while(count < stop) {
            temp = pLast;
            pLast = pLast->next;
            temp->next = pMid;
            pMid = temp;
            ++count;
        }
        return ret;
    }
};

int main(void) {
    auto head = new ListNode(1);
    auto head1 = new ListNode(3);
    head->next = head1;
    auto head2 = new ListNode(2);
    head1->next = head2;
    auto head3 = new ListNode(4);
    head2->next = head3;
    auto head4 = new ListNode(3);
    head3->next = head4;
    auto head5 = new ListNode(2);
    head4->next = head5;
    auto head6 = new ListNode(1);
    head5->next = head6;
    Solution s;
    auto v = s.isPalindrome(head);
    cout << v <<endl;
}
