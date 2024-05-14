/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return hasPathSum(root, targetSum, 0);
    }
    bool hasPathSum(TreeNode *root, int targetSum, int preSum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val + preSum == targetSum) return true;
        }
        if (root->left != nullptr) {
            if (hasPathSum(root->left, targetSum, preSum + root->val)) return true;
        }
        if (root->right != nullptr) {
            if (hasPathSum(root->right, targetSum, preSum + root->val)) return true;
        }
        return false;
    }
};
// @lc code=end
