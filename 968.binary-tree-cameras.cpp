/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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

using namespace std;

class Solution {  
public:

    enum class state { camera, covered, uncovered };

    unsigned cnt {0};

    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        auto s = traversal(root);
        if (s == state::uncovered) cnt += 1;
        return cnt;
    }

    state traversal(TreeNode *node) {
        if (node == nullptr) return state::covered;
        state l = traversal(node->left), r = traversal(node->right);
        if (l == state::uncovered || r == state::uncovered) {
            cnt += 1; return state::camera;
        }
        if (l == state::camera || r == state::camera) return state::covered;
        return state::uncovered;
    }

  };
// @lc code=end
