/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        stack<TreeNode *> st;
        st.push(root);
        int acc = 0;
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            if (node != nullptr) {
                if (node->left != nullptr) st.push(node->left);
                st.push(node); st.push(nullptr);
                if (node->right != nullptr) st.push(node->right);
            } else {
                node = st.top(); st.pop();
                node->val += acc;
                acc = node->val;
            }
        }
        return root;
    }
};
// @lc code=end
