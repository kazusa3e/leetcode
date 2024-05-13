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

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        vector<string> ret;
        binaryTreePaths(root, "", move(ret));
        return ret;
    }
    void binaryTreePaths(TreeNode *root, const string prefix, vector<string> &&ret) {
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(prefix + to_string(root->val));
        }
        if (root->left != nullptr) {
            binaryTreePaths(root->left, prefix + to_string(root->val) + "->", move(ret));
        }
        if (root->right != nullptr) {
            binaryTreePaths(root->right, prefix + to_string(root->val) + "->", move(ret));
        }
    }
};
// @lc code=end
