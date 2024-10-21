/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
#include <limits>
#include <stack>

using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<TreeNode *> st; st.push(root);
        stack<int> limits; limits.push(numeric_limits<int>::min());
        unsigned cnt = 0;
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            int limit = limits.top(); limits.pop();
            if (node != nullptr) {
                if (node->left != nullptr) {
                    st.push(node->left);
                    limits.push(max(limit, node->val));
                }
                if (node->right != nullptr) {
                    st.push(node->right);
                    limits.push(max(limit, node->val));
                }

                st.push(node); st.push(nullptr);
                limits.push(limit); limits.push(0);
            } else {
                node = st.top(); st.pop();
                limit = limits.top(); limits.pop();
                if (node->val >= limit) cnt += 1;

            }
        }
        return cnt;
    }
};
// @lc code=end
