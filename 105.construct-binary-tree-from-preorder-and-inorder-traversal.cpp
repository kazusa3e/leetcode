/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

using namespace std;

class Solution {
public:

    using iterator = vector<int>::const_iterator;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
    }

    TreeNode *buildTree(
        iterator preorder_begin, iterator preorder_end,
        iterator inorder_begin, iterator inorder_end) {
        auto root = new TreeNode { *preorder_begin };
        if (distance(preorder_begin, preorder_end) == 1) return root;

        const auto pos = find(inorder_begin, inorder_end, *preorder_begin);
        const auto left_cnt = distance(inorder_begin, pos);

        const auto left_inorder_begin = inorder_begin, left_inorder_end = pos,
            right_inorder_begin = pos + 1, right_inorder_end = inorder_end;
        const auto left_preorder_begin = preorder_begin + 1, left_preorder_end = left_preorder_begin + left_cnt,
            right_preorder_begin = left_preorder_end, right_preorder_end = preorder_end;

        if (distance(left_preorder_begin, left_preorder_end) != 0) {
            root->left = buildTree(left_preorder_begin, left_preorder_end, left_inorder_begin, left_inorder_end);
        }
        if (distance(right_preorder_begin, right_preorder_end) != 0) {
            root->right = buildTree(right_preorder_begin, right_preorder_end, right_inorder_begin, right_inorder_end);
        }
        return root;
    }
};
// @lc code=end
