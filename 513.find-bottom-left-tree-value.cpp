/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return -1;
        queue<TreeNode *> nodeQu;
        nodeQu.push(root);
        int ret = -1;
        while (!nodeQu.empty()) {
            bool flag = false;
            for (int sz = nodeQu.size(); sz != 0; --sz) {
                TreeNode *node = nodeQu.front(); nodeQu.pop();
                if (node->left != nullptr) nodeQu.push(node->left);
                if (node->right != nullptr) nodeQu.push(node->right);
                if (!flag) {
                    ret = node->val; flag = true;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
