/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto leave1 = leaves(root1), leave2 = leaves(root2);
        return leave1.size() == leave2.size()
            && equal(leave1.begin(), leave1.end(), leave2.begin());
    }

    vector<int> leaves(TreeNode *root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        stack<TreeNode *> st; st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            if (node != nullptr) {
                st.push(node); st.push(nullptr);
                if (node->right != nullptr) st.push(node->right);
                st.push(node); st.push(nullptr);
                if (node->left != nullptr) st.push(node->left);
            } else {
                node = st.top(); st.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    ret.push_back(node->val);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
