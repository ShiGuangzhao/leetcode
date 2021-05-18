/*************************************************************************
    > File Name: 7_重建二叉树.cpp
    > Author: ShiGuangzhao
    > Mail: Guangzhao_Shi@163.com 
    > Created Time: 2021年03月19日 星期五 17时20分20秒
 ************************************************************************/

// TODO: wrong

#include <iostream>
#include <stack>
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
        TreeNode *root = nullptr;
        TreeNode *trueRoot = nullptr;
        stack<int> stk;
        auto preIt = preorder.begin();
        auto inIt = inorder.begin();
        auto count = 0;

        while(preIt != preorder.end()) {
            // 前序遍历入栈直到有一个和中序相同的元素
            // 此时出栈，直到有不同的元素
            if(*preIt != *inIt) {
                stk.push(*preIt++);
            }
            else {
                root = new TreeNode(*inIt);
                cout << "test1: " <<  *preIt << endl;
                if(*inIt++ == preorder[0]) {
                    trueRoot = root;
                }
                ++preIt;
                while(!stk.empty()) {
                    auto tmp = new TreeNode(*inIt);
                    cout << "test2: " <<  *preIt << endl;
                    if(*inIt == preorder[0]) {
                        trueRoot = tmp;
                    }
                    if(*inIt == stk.top()) {
                        tmp->left = root;
                        root = tmp;
                        stk.pop();
                    }
                    else {
                        root->right = tmp;
                        ++preIt;
                    }
                    ++inIt;
                }
            }
        }
        return trueRoot;
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

