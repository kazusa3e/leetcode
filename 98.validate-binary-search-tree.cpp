/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }

    bool isValidBST(const TreeNode *root, const long lower_boundary, const long upper_boundary) const {
        // bounds are inclusive
        if (root == nullptr) return true;
        if (root->val < lower_boundary || root->val > upper_boundary) return false;
        return isValidBST(root->left, lower_boundary, root->val - 1l)
            && isValidBST(root->right, root->val + 1l, upper_boundary);
    }
};
// @lc code=end
