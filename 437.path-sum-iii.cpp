/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




class Solution {

public:
    unsigned num_paths {0};

public:
    int pathSum(TreeNode* root, int targetSum) {
        traversal(root, targetSum);
        return num_paths;
    }

    void traversal(TreeNode *root, long targetSum) {
        if (root == nullptr) return;
        test(root, targetSum);
        traversal(root->left, targetSum);
        traversal(root->right, targetSum);
    }

    void test(TreeNode *root, long targetSum) {
        if (root == nullptr) return;
        if (root->val == targetSum) num_paths += 1;
        test(root->left, targetSum - root->val);
        test(root->right, targetSum - root->val);
    }

};
// @lc code=end
