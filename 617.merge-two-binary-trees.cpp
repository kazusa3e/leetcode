/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <queue>
using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        queue<TreeNode *> qu;
        qu.push(root1); qu.push(root2);
        while (!qu.empty()) {
            TreeNode *n1 = qu.front(); qu.pop();
            TreeNode *n2 = qu.front(); qu.pop();
            n1->val += n2->val;
            if (n1->left != nullptr && n2->left != nullptr) {
                qu.push(n1->left); qu.push(n2->left);
            }
            if (n1->right != nullptr && n2->right != nullptr) {
                qu.push(n1->right); qu.push(n2->right);
            }
            if (n1->left == nullptr && n2->left != nullptr) {
                n1->left = n2->left;
            }
            if (n1->right == nullptr && n2->right != nullptr) {
                n1->right = n2->right;
            }
        }
        return root1;
    }
};
// @lc code=end
