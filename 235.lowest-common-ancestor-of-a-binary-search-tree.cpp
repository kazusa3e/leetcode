/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
        auto m_min = min(p->val, q->val), m_max = max(p->val, q->val);
        if (root->val > m_min && root->val < m_max) return root;
        if (root->val < m_min) return lowestCommonAncestor(root->right, p, q);
        if (root->val > m_max) return lowestCommonAncestor(root->left, p, q);
        return {};
    }
};
// @lc code=end
