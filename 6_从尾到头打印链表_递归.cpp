/*************************************************************************
    > File Name: 6_从尾到头打印链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月17日 星期三 18时42分09秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void pushVector(ListNode *head, vector<int> &vec) {
        if(head != nullptr) {
            pushVector(head->next, vec);
            vec.push_back(head->val);
        }
    }

public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        pushVector(head, ret);
        return ret;
    }
};

int main(void) {
    auto head = new ListNode(1);
    auto head1 = new ListNode(2);
    head->next = head1;
    auto head2 = new ListNode(3);
    head1->next = head2;
    auto head3 = new ListNode(4);
    head2->next = head3;
    Solution s;
    auto v = s.reversePrint(head);
    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
}
