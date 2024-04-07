/*
 * @lc app=leetcode id=530 lang=java
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start

import java.util.Stack;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public int getMinimumDifference(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);
        TreeNode prev = null;
        int diff = Integer.MAX_VALUE;
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (node.right != null)
                    stack.add(node.right);
                stack.add(node);
                stack.add(null);
                if (node.left != null)
                    stack.add(node.left);
            } else {
                node = stack.pop();
                if (prev != null)
                    diff = Math.min(diff, Math.abs(prev.val - node.val));
                prev = node;
            }
        }
        return diff;
    }
}
// @lc code=end
