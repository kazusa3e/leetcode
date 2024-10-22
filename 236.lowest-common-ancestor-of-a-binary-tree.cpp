/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        auto l = lowestCommonAncestor(root->left, p, q),
            r = lowestCommonAncestor(root->right, p, q);
        if (l != nullptr && r != nullptr) return root;
        if (l != nullptr ^ r != nullptr) {
            return (l == nullptr) ? r : l;
        }
        return nullptr;
    }
};
// @lc code=end
