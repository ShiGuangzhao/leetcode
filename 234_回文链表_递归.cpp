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
    bool compare(ListNode *head, ListNode **begin) {
        if(head != nullptr) {
            if(!compare(head->next, begin) || head->val != (*begin)->val) {
                return false;
            }
            // 上一级比较为真   
            *begin = (*begin)->next;
            return true;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) {
            return true;
        }
        ListNode *begin = head;
        return compare(head, &begin);
    }
};

int main(void) {
    auto head = new ListNode(1);
    auto head1 = new ListNode(2);
    head->next = head1;
    auto head2 = new ListNode(2);
    head1->next = head2;
    // auto head3 = new ListNode(1);
    // head2->next = head3;
    Solution s;
    auto v = s.isPalindrome(head);
    cout << v <<endl;
}
