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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) return nullptr;
        TreeNode *root = new TreeNode{postorder.back()};
        if (postorder.size() == 1) return root;
        auto pos = find(inorder.begin(), inorder.end(), postorder.back());
        vector<int> inorder_leftpart = {inorder.begin(), pos},
                    inorder_rightpart = {pos + 1, inorder.end()};
        vector<int> postorder_leftpart = {postorder.begin(), postorder.begin() + inorder_leftpart.size()},
                    postorder_rightpart = {postorder.begin() + inorder_leftpart.size(), postorder.begin() + inorder_leftpart.size() + inorder_rightpart.size()};
        root->left = buildTree(inorder_leftpart, postorder_leftpart);
        root->right = buildTree(inorder_rightpart, postorder_rightpart);
        return root;
    }
};
// @lc code=end
