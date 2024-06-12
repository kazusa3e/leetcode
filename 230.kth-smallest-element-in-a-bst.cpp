/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            if (node != nullptr) {
                if (node->right != nullptr) st.push(node->right);
                st.push(node); st.push(nullptr);
                if (node->left != nullptr) st.push(node->left);
            } else {
                node = st.top(); st.pop();
                if (k == 1) return node->val;
                k -= 1;
            }
        }
        return -1;
    }
};
// @lc code=end
