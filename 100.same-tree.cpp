/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> qu;
        qu.push(p); qu.push(q);
        while (!qu.empty()) {
            TreeNode *left = qu.front(); qu.pop();
            TreeNode *right = qu.front(); qu.pop();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr ^ right == nullptr) return false;
            if (left->val != right->val) return false;
            qu.push(left->left); qu.push(right->left);
            qu.push(left->right); qu.push(right->right);
        }
        return true;
    }
};
// @lc code=end
