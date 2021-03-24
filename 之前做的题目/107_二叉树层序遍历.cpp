/*************************************************************************
    > File Name: 107_二叉树层序遍历.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2020年09月06日 星期日 20时20分18秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ret;
        vector<TreeNode *> oldlayer{root};
        while(1) {
            vector<TreeNode *> layer;
            vector<int> oldlayer_val;
            for(auto node: oldlayer) {
                oldlayer_val.push_back(node->val);
                if(node->left != NULL) {
                    layer.push_back(node->left);
                }
                if(node->right != NULL) {
                    layer.push_back(node->right);
                }
            }
            ret.push_back(oldlayer_val);
            if(layer.empty()) {
                break;
            }
            else {
                oldlayer = layer;
            }
        }
        vector<vector<int>> newret(ret.rbegin(), ret.rend());
        return newret;
    }
};
