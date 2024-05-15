/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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

#include <vector>
#include <numeric>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        pathSum(root, targetSum, {}, move(ret));
        return ret;
    }
    void pathSum(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &&ret) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (accumulate(path.begin(), path.end(), 0) == targetSum) {
                ret.push_back(path);
            }
        }
        if (root->left != nullptr) {
            pathSum(root->left, targetSum, path, move(ret));
        }
        if (root->right != nullptr) {
            pathSum(root->right, targetSum, path, move(ret));
        }
    }
};
// @lc code=end
