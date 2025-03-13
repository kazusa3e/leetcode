/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums.cbegin(), nums.cend());
    }

    TreeNode *constructMaximumBinaryTree(
        vector<int>::const_iterator begin, 
        vector<int>::const_iterator end) const {
        if (begin == end) return nullptr;
        const auto pos = max_element(begin, end);
        TreeNode *root = new TreeNode { *pos };
        root->left = constructMaximumBinaryTree(begin, pos);
        root->right = constructMaximumBinaryTree(pos + 1, end);
        return root;
    }
};
// @lc code=end
