/*************************************************************************
    > File Name: 148_排序链表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年05月21日 星期五 14时01分59秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
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
    using pNode = ListNode *;
    using pList = pNode;
    // 将一个节点插入到一个已排序的链表中
    // 返回插入后的链表
    // 链表从小到大排序
    // 假设都不为空
    pList insertNode(pList head, pNode node) {
        if(node->val <= head->val) {
            node->next = head;
            return node;
        }
        else {
            auto ret = head;
            auto last = head;
            head = head->next;
            while(head != nullptr and head->val < node->val) {
                last = head;
                head = head->next;
            }
            last->next = node;
            node->next = head;
            return ret;
        }

    }

    class cmp {
    public:
        bool operator()(pNode a, pNode b) {
            return a->val > b->val;
        }
    };

public:
    // 超出时间限制
    // 插入排序
    ListNode* sortList_Insert(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        auto ret = head;
        head = head->next;
        ret->next = nullptr;
        while(head != nullptr) {
            auto tmp = head->next;
            ret = insertNode(ret, head);
            head = tmp;
        }
        return ret;
    }

    // 栈排序
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        std::priority_queue<pNode, vector<pNode>,cmp> heap;
        while(head != nullptr) {
            heap.push(head);
            head = head->next;
        }
        auto ret = heap.top();
        auto last = ret;
        heap.pop();
        while(!heap.empty()) {
            last->next = heap.top();
            last = last->next;
            heap.pop();
        }
        last->next = nullptr;
        return ret;
    }
        
};

int main(void) {
    ListNode *head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    Solution s;
    head = s.sortList(head);
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
