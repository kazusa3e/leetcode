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
#include <queue>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth += 1;
            for (int sz = q.size(); sz != 0; --sz) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return depth;
    }
};