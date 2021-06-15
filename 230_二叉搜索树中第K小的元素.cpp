/*************************************************************************
    > File Name: 230_二叉搜索树中第K小的元素.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月15日 星期二 14时20分29秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int count = 0;
    int ret = 0;
    void kthSmallest_Iter(TreeNode* root, int k) {
        if(root == nullptr) {
            return;
        }
        kthSmallest_Iter(root->left, k);
        if(k <= ++count) {
            if(k == count) {
                ret = root->val;
            }
            return;
        }
        kthSmallest_Iter(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmallest_Iter(root, k);
        return ret;
    }
};
