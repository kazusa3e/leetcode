/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return {};
        stack<TreeNode *> st; st.push(root);

        TreeNode *prev = nullptr;
        unsigned times = 1, max_times = 1;
        vector<int> ret;


        while (!st.empty()) {
            auto node = st.top(); st.pop();
            if (node != nullptr) {
                if (node->right != nullptr) st.push(node->right);
                st.push(node); st.push(nullptr);
                if (node->left != nullptr) st.push(node->left);
            } else {
                node = st.top(); st.pop();
                if (prev == nullptr) {
                    prev = node; ret.push_back(node->val); continue;
                }
                (node->val == prev->val) ? times += 1 : times = 1;
                prev = node;
                if (times > max_times) {
                    ret.clear(); ret.push_back(node->val); max_times = times;
                } else if (times == max_times) {
                    ret.push_back(node->val);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
