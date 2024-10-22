/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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

#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> qu; qu.push(root);
        long m_sum = numeric_limits<long>::min(), m_level = 0;
        unsigned level = 1;
        while (!qu.empty()) {
            unsigned sz = qu.size();
            long level_sum = 0;
            for (unsigned ix = 0; ix != sz; ++ix) {
                TreeNode *node = qu.front(); qu.pop();
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
                level_sum += node->val;
            }
            if (level_sum > m_sum) {
                m_sum = level_sum; m_level = level;
            }
            level += 1;
        }
        return m_level;
    }
};
// @lc code=end
