/*
 * @lc app=leetcode id=112 lang=java
 *
 * [112] Path Sum
 */

// @lc code=start

import java.util.Stack;
import java.util.AbstractMap.SimpleEntry;

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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)
            return false;
        Stack<SimpleEntry<TreeNode, Integer>> stack = new Stack<>();
        stack.push(new SimpleEntry<>(root, targetSum));
        boolean ret = false;
        while (!stack.empty()) {
            SimpleEntry<TreeNode, Integer> entry = stack.pop();
            if (entry != null) {
                TreeNode node = entry.getKey();
                int target = entry.getValue();
                if (node.left != null) {
                    stack.push(new SimpleEntry<>(node.left, target - node.val));
                }
                if (node.right != null) {
                    stack.push(new SimpleEntry<>(node.right, target - node.val));
                }
                stack.push(new SimpleEntry<>(node, target));
                stack.push(null);
            } else {
                entry = stack.pop();
                TreeNode node = entry.getKey();
                int target = entry.getValue();
                if (node.left == null && node.right == null && node.val == target)
                    ret = true;
            }
        }
        return ret;
    }
}
// @lc code=end
