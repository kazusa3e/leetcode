/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key == root->val) {
            if (root->left == nullptr && root->right == nullptr) {
                delete root; return nullptr;
            }
            if (root->left != nullptr ^ root->right != nullptr) {
                if (root->left != nullptr) {
                    auto tmp = root->left; delete root; return tmp;
                }
                if (root->right != nullptr) {
                    auto tmp = root->right; delete root; return tmp;
                }
            }
            // find the right most node in left subtree
            auto iter = root->left;
            while (iter->right != nullptr) iter = iter->right;
            auto ret = new TreeNode { iter->val, deleteNode(root->left, iter->val), root->right };
            delete root;
            return ret;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        } else {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};
// @lc code=end
