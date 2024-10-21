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
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        return pathSum(root, targetSum, {});
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum, vector<int> prefix) {
        prefix.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return (root->val == targetSum)
                ? vector<vector<int>> { prefix }
                : vector<vector<int>> {};
        }
        vector<vector<int>> l, r;
        if (root->left != nullptr) {
            l = pathSum(root->left, targetSum - root->val, prefix);
        }
        if (root->right != nullptr) {
            r = pathSum(root->right, targetSum - root->val, prefix);
        }
        move(r.begin(), r.end(), back_inserter(l));
        return l;
    }
};
// @lc code=end
