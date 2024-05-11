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
            TreeNode *top = st.top();
            st.pop();
            ret.push_back(top->val);
            if (top->left != nullptr) st.push(top->left);
            if (top->right != nullptr) st.push(top->right);
       }
       reverse(ret.begin(), ret.end());
       return ret;
    }

};
// @lc code=end
