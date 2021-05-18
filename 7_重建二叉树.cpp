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
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        auto itRoot = find(inorder.begin(), inorder.end(), preorder[0]);
        // 不存在找不到的情况，所以不考虑
        auto M = itRoot - inorder.begin();
        auto N = inorder.end() - itRoot - 1;
        // cout << M << N << endl;

        vector<int> preLeft{preorder.begin() + 1, preorder.begin() + M + 1};
        vector<int> inLeft{inorder.begin(), itRoot};
        root->left = buildTree(preLeft, inLeft);

        vector<int> preRight{preorder.begin() + M + 1, preorder.end()};
        vector<int> inRight{itRoot + 1, inorder.end()};
        root->right = buildTree(preRight, inRight);

        return root;
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

