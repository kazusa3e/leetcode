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
        bool l = false, r = false;
        if (root->left != nullptr) {
            l = hasPathSum(root->left, targetSum, preSum + root->val);
        }
        if (root->right != nullptr) {
            r = hasPathSum(root->right, targetSum, preSum + root->val);
        }
        return l || r;
    }
};
// @lc code=end
