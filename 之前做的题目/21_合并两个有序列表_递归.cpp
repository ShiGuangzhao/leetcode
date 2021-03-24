/*************************************************************************
    > File Name: 21_合并两个有序列表.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月22日 星期六 10时26分32秒
 ************************************************************************/

#include <iostream>
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
    // 都不为nullptr且l1.var < l2.var;
    ListNode* mergeLists(ListNode* lsmall, ListNode* lgreat) {
        auto ret = lsmall;
        while(true) {
            if(lsmall->next == nullptr) {
                lsmall->next = lgreat;
                break;
            }
            if(lsmall->next->val <= lgreat->val) {
                lsmall = lsmall->next;
            }
            else {
                lsmall->next = mergeLists(lgreat, lsmall->next);
                break;
            }
        }
        return ret;
    }

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret;
        // 空指针的情况
        if(l1 == nullptr) {
            return l2;
        }
        else if(l2 == nullptr) {
            return l1;
        }
        // 都不是空指针，找的小的一个l，ret等于小的l
        // l = l->next，直到l->next > 另一个la
        // 如果上一步l->next等于nullptr，l->next = la，返回
        // 如果找到大于la的，则l->next = mergeLists(la, l->next)
        else {
            ListNode *lsmall, *lgreat;
            ret = lsmall = (l1->val <= l2->val)? l1: l2;
            lgreat = (l1->val <= l2->val)? l2: l1;
            while(true) {
                if(lsmall->next == nullptr) {
                    lsmall->next = lgreat;
                    break;
                }
                if(lsmall->next->val <= lgreat->val) {
                    lsmall = lsmall->next;
                }
                else {
                    lsmall->next = mergeLists(lgreat, lsmall->next);
                    break;
                }
            }
        }
        return ret;
    }
};
