/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        queue<TreeNode *> q;
        q.push(root->left); q.push(root->right);
        while (!q.empty()) {
            TreeNode *left = q.front(); q.pop();
            TreeNode *right = q.front(); q.pop();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr ^ right == nullptr) return false;
            if (left->val != right->val) return false;
            q.push(left->left); q.push(right->right);
            q.push(left->right); q.push(right->left);
        }
        return true;
    }
};
// @lc code=end
