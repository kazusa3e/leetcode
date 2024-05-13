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

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr ^ root->right == nullptr) {
            if (root->left == nullptr) return 1 + minDepth(root->right);
            if (root->right == nullptr) return 1 + minDepth(root->left);
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};