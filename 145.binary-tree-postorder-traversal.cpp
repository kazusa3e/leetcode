/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> ret;
       if (root == nullptr) return ret;
       stack<TreeNode *> st;
       st.push(root);
       while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (node != nullptr) {
                st.push(node); st.push(nullptr);
                if (node->right != nullptr) st.push(node->right);
                if (node->left != nullptr) st.push(node->left);
            } else {
                node = st.top();
                st.pop();
                ret.push_back(node->val);
            }
       }
       return ret;
    }

};
// @lc code=end
