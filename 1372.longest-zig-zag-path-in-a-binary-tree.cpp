/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
#include <vector>

using namespace std;

class Solution {

public:
    unsigned max_length {0};

public:
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, true, 0);
        dfs(root, false, 0);
        return max_length;

    }

    // false -> left, true -> right
    void dfs(TreeNode *root, bool direction, unsigned prev_length) {
        if (root == nullptr) return;
        max_length = max(max_length, prev_length);

        if (!direction) {
            dfs(root->left, !direction, prev_length + 1);
            dfs(root->right, false, 1);
        } else {
            dfs(root->right, !direction, prev_length + 1);
            dfs(root->left, true, 1);
        }
    }
};
// @lc code=end
