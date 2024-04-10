/*
 * @lc app=leetcode id=538 lang=java
 *
 * [538] Convert BST to Greater Tree
 */

// @lc code=start

import java.util.Stack;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode convertBST(TreeNode root) {
        if (root == null) return null;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        int acc = 0;
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (node.left != null) stack.push(node.left);
                stack.push(node); stack.push(null);
                if (node.right != null) stack.push(node.right);
            } else {
                node = stack.pop();
                acc += node.val;
                node.val = acc;
            }
        }
        return root;
    }
}
// @lc code=end

