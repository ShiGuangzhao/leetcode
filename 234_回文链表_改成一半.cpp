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
        if(head == nullptr) {
            return true;
        }
        auto oralHead = head;
        size_t size = 0;
        while(head) {
            ++size;
            head = head->next;
        }
        auto stop = size / 2;
        head = oralHead;

        auto a = new int[stop];
        auto count = 0;
        while(head && count < stop) {
            a[count] = head->val;
            head = head->next;
            ++count;
        }
        if(size % 2 != 0) {
            head = head->next;
        }

        --count;
        while(head) {
            if(a[count--] != head->val) {
                return false;
            }
            head = head->next;
        }
        delete []a;
        return true;
    }
};

int main(void) {
    auto head = new ListNode(1);
    auto head1 = new ListNode(2);
    head->next = head1;
    auto head2 = new ListNode(2);
    head1->next = head2;
    auto head3 = new ListNode(1);
    head2->next = head3;
    Solution s;
    auto v = s.isPalindrome(head);
    cout << v <<endl;
}
