/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
#include <vector>

using namespace std;

class Solution {
public:

    using iterator = vector<int>::const_iterator;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return nullptr;
        return buildTree(inorder.cbegin(), inorder.cend(), postorder.cbegin(), postorder.cend());
    }

    TreeNode *buildTree(
        iterator inorder_begin, iterator inorder_end,
        iterator postorder_begin, iterator postorder_end) {
        auto root = new TreeNode { *(postorder_end - 1) };
        if (distance(postorder_begin, postorder_end) == 1) return root;

        auto pos = find(inorder_begin, inorder_end, *(postorder_end - 1));
        auto left_cnt = distance(inorder_begin, pos);

        auto left_inorder_begin = inorder_begin, left_inorder_end = pos,
            right_inorder_begin = pos + 1, right_inorder_end = inorder_end;
        auto left_postorder_begin = postorder_begin, left_postorder_end = left_postorder_begin + left_cnt,
            right_postorder_begin = left_postorder_end, right_postorder_end = postorder_end - 1;

        if (distance(left_inorder_begin, left_inorder_end) != 0) {
            root->left = buildTree(left_inorder_begin, left_inorder_end, left_postorder_begin, left_postorder_end);
        }
        if (distance(right_inorder_begin, right_inorder_end) != 0) {
            root->right = buildTree(right_inorder_begin, right_inorder_end, right_postorder_begin, right_postorder_end);
        }
        return root;
    }
};
// @lc code=end