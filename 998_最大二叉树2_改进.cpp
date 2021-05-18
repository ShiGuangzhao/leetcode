/*************************************************************************
    > File Name: 998_最大二叉树2.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月23日 星期二 09时07分00秒
 ************************************************************************/

#include <algorithm>
#include <ios>
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
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *ret = root;
        if(root == nullptr || val > root->val) {
            auto ret = new TreeNode(val, root, nullptr);
            return ret; 
        }
        // root != nullptr
        while(root->right != nullptr && root->right->val > val) {
            root = root->right;
        }
        root->right = new TreeNode(val, root->right, nullptr);
        return ret;
    }

    void printTree(TreeNode *root){
        if(root != nullptr) {
            cout << root->val << endl;
            printTree(root->left);
            printTree(root->right);
        }
    }
};

int main(void) {
    auto root = new TreeNode(1);
    Solution s;
    auto temp = s.insertIntoMaxTree(root, 2);
    s.printTree(temp);
}
