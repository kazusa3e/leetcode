/*
 * @lc app=leetcode id=257 lang=java
 *
 * [257] Binary Tree Paths
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;
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
    private static class Context {
        TreeNode node;
        String prefix;
        public Context(TreeNode node, String prefix) {
            this.node = node;
            this.prefix = prefix;
        }
    }
    public List<String> binaryTreePaths(TreeNode root) {
        Stack<Context> stack = new Stack<>();
        List<String> results = new ArrayList<>();
        if (root.left == null && root.right == null) return List.of(String.valueOf(root.val));
        if (root.right != null) stack.push(new Context(root.right, String.valueOf(root.val)));
        if (root.left != null) stack.push(new Context(root.left, String.valueOf(root.val)));
        while (!stack.empty()) {
            Context ctx = stack.pop();
            if (ctx != null) {
                TreeNode node = ctx.node; String prefix = ctx.prefix + "->" + String.valueOf(node.val);
                if (node.right != null) stack.push(new Context(node.right, prefix));
                if (node.left != null) stack.push(new Context(node.left, prefix));
                stack.push(ctx); stack.push(null);
            } else {
                ctx = stack.pop();
                TreeNode node = ctx.node; String prefix = ctx.prefix + "->" + String.valueOf(node.val);
                if (node.left == null && node.right == null) {
                    results.add(prefix);
                }
            }
        }
        return results;
    }
}
// @lc code=end
