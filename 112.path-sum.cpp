/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        stack<TreeNode *> st;
        stack<int> presum;
        st.push(root);
        presum.push(0);
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            int sum = presum.top(); presum.pop();
            if (node != nullptr) {
                if (node->right != nullptr) {
                    st.push(node->right);
                    presum.push(sum + node->val);
                }
                if (node->left != nullptr) {
                    st.push(node->left);
                    presum.push(sum + node->val);
                }
                st.push(node); st.push(nullptr); presum.push(sum);
            } else {
                node = st.top(); st.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    if (sum + node->val == targetSum) return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
