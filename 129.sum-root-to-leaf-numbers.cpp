/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
private:
    int sum_ {};
    void sumNumbers(TreeNode *root, const int presum) {
        if (root->left == nullptr && root->right == nullptr) {
            sum_ += presum * 10 + root->val;
        }
        if (root->left != nullptr) sumNumbers(root->left, presum * 10 + root->val);
        if (root->right != nullptr) sumNumbers(root->right, presum * 10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        sumNumbers(root, 0);
        return sum_;
    }
};
// @lc code=end
