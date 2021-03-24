/*************************************************************************
    > File Name: 7_重建二叉树.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月19日 星期五 17时20分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // 递归
    // 前序遍历第一个节点为根节点
    // 然后在中序遍历中找到根节点，根节点前为左子树（M），之后为右子树（M）
    // 在前序遍历中除根节点外的前M个为左子树，后N个为右子树
    // 对左右子树递归，没有子树了则返回
    
    using iter_t = vector<int>::iterator;
    TreeNode* buildSubTree(iter_t preBeg, iter_t preEnd, iter_t inBeg, iter_t inEnd) {
        if(preEnd == preBeg) {
            return NULL;
        }
        TreeNode *root = new TreeNode(*preBeg);
        auto itRoot = find(inBeg, inEnd, root->val);
        // 不存在找不到的情况，所以不考虑
        auto M = itRoot - inBeg;
        auto N = inEnd - itRoot - 1;
        // cout << M << N << endl;

        root->left = buildSubTree(preBeg + 1, preBeg + M + 1, inBeg, itRoot);
        root->right = buildSubTree(preBeg + M + 1, preEnd, itRoot + 1, inEnd); 
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildSubTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
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
    vector<int> pre{1, 2, 4, 8, 7, 3, 5, 6}; 
    vector<int> in{8, 4, 2, 7, 1, 5, 3, 6};
    Solution s;
    s.printTree(s.buildTree(pre, in));
}

