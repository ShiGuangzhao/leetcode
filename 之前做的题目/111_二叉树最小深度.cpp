/*************************************************************************
    > File Name: 111_二叉树最小深度.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年08月21日 星期五 10时33分47秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        queue<pair<TreeNode *, int>> que;
        pair<TreeNode *, int> node;
        que.push({root, 1});
        while(true) {
            node = que.front();
            que.pop();
            if(node.first->left == NULL && node.first->right == NULL) {
                return node.second;
            }
            if(node.first->right != NULL) {
                que.push({node.first->right, node.second + 1});
            }
            if(node.first->left != NULL) {
                que.push({node.first->left, node.second + 1});
            }
        }
    }
};
