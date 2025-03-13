/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
#include <cstdlib>
#include <limits>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return 0;
        unsigned min_difference = numeric_limits<unsigned>::max();
        TreeNode *prev = nullptr;
        stack<TreeNode *> st; st.push(root);
        while (!st.empty()) {
            auto node = st.top(); st.pop();
            if (node != nullptr) {
                if (node->right != nullptr) st.push(node->right);
                st.push(node); st.push(nullptr);
                if (node->left != nullptr) st.push(node->left);
            } else {
                node = st.top(); st.pop();
                if (prev == nullptr) {
                    prev = node;
                } else {
                    min_difference = min(min_difference, (unsigned) abs(prev->val - node->val));
                    prev = node;
                }
            }
        }
        return min_difference;
    }
};
// @lc code=end
