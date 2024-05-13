/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode *left = root->left, *right = root->right;
        size_t leftDepth = 0, rightDepth = 0;
        while (left != nullptr) {
            left = left->left; leftDepth += 1;
        }
        while (right != nullptr) {
            right = right->right; rightDepth += 1;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end
