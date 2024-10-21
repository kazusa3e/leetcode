/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
#include <limits>

using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, numeric_limits<int>::min());
    }

    int goodNodes(TreeNode *root, int limit) {
        if (root == nullptr) return 0;
        int l = goodNodes(root->left, max(root->val, limit)),
            r = goodNodes(root->right, max(root->val, limit));
        return (root->val >= limit) ? 1 + l + r : l + r;
    }
};
// @lc code=end
