/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int m = INT_MIN;
            for (int sz = q.size(); sz != 0; --sz) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                m = max(m, node->val);
            }
            ret.push_back(m);
        }
        return ret;
    }
};
// @lc code=end
