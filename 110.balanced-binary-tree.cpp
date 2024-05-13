/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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

#include <algorithm>

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return depth(root) != -1;
    }
    int depth(TreeNode *root) {
        if (root == nullptr) return 0;
        int leftDepth = depth(root->left);
        if (leftDepth == -1) return -1;
        int rightDepth = depth(root->right);
        if (rightDepth == -1) return -1;
        return (abs(leftDepth - rightDepth) > 1) ? -1 : 1 + max(leftDepth, rightDepth);
    }
};
// @lc code=end
