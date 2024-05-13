/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode *> nodeSt;
        stack<string> prefixSt;
        vector<string> ret;
        nodeSt.push(root); prefixSt.push("");
        while (!nodeSt.empty()) {
            TreeNode *node = nodeSt.top(); nodeSt.pop();
            string prefix = prefixSt.top(); prefixSt.pop();
            if (node->left == nullptr && node->right == nullptr) {
                ret.push_back(prefix + to_string(node->val));
            }
            if (node->left != nullptr) {
                nodeSt.push(node->left); prefixSt.push(prefix + to_string(node->val) + "->");
            }
            if (node->right != nullptr) {
                nodeSt.push(node->right); prefixSt.push(prefix + to_string(node->val) + "->");
            }
        }
        return ret;
    }
};
// @lc code=end
