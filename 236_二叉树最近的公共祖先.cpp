/*************************************************************************
    > File Name: 236_二叉树最近的公共祖先.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年06月15日 星期二 15时08分43秒
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    const int RIGHT = 1;
    const int ALL_NILL = 0;
    const int ALL_RIGHT = 2;
    TreeNode *ret;

    int afterOrder(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return ALL_NILL;
        }
        auto left = afterOrder(root->left, p, q);
        if(left == ALL_RIGHT)   return ALL_RIGHT;

        auto right = afterOrder(root->right, p, q);
        if(right == ALL_RIGHT)   return ALL_RIGHT;
        
        auto mid = ((p == root) or (q == root))? RIGHT: 0;
        auto result = left + right + mid;
        if(result == ALL_RIGHT) ret = root;
        return result;
    }

public:
    // 后序遍历
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        afterOrder(root, p, q);
        return ret;
    }
};
