/*************************************************************************
    > File Name: 110_平衡二叉树.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月23日 星期二 19时03分17秒
 ************************************************************************/

#include <cmath>
#include <iostream>
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
    int height(TreeNode *root) {
        if(root == nullptr) {
            return 0;
        }
        int left = height(root->left);
        if(left == -1)
           return  -1;
        int right = height(root->right);
        if(right == -1 || std::abs(left - right) > 1)
           return  -1;
        else
            return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
