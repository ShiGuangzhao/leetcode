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
private:
    void readA(TreeNode *root, vector<int> &vec) {
        if(root != nullptr) {
            readA(root->left, vec);
            vec.push_back(root->val);
            readA(root->right, vec);
        }
    }

    TreeNode *Construct(vector<int>::iterator &it,int beg, int end) {
        if(beg == end) {
            return nullptr;
        }
        auto maxIt = std::max_element(it + beg, it + end);
        auto root = new TreeNode(*maxIt);
        root->left = Construct(it, beg, maxIt - it);
        root->right = Construct(it, maxIt -it + 1, end);
        return root;
    }

public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> A;
        readA(root, A);
        A.push_back(val);
        auto begIt = A.begin();
        return Construct(begIt, 0, A.size());
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
