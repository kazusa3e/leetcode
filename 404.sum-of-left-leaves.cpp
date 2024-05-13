/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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

#include <stack>

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<TreeNode *> nodeSt;
        nodeSt.push(root);
        int sum = 0;
        while (!nodeSt.empty()) {
            TreeNode *node = nodeSt.top(); nodeSt.pop();
            if (node != nullptr) {
                nodeSt.push(node); nodeSt.push(nullptr);
                if (node->right != nullptr) nodeSt.push(node->right);
                if (node->left != nullptr) nodeSt.push(node->left);
            } else {
                node = nodeSt.top(); nodeSt.pop();
                if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
                    sum += node->left->val;
                }
            }
        }
        return sum;
    }
};
// @lc code=end
