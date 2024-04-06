/*
 * @lc app=leetcode id=113 lang=java
 *
 * [113] Path Sum II
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;
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
    private static class Context {
        TreeNode node;
        int target;
        List<Integer> prefix;

        public Context(TreeNode n, int t, List<Integer> p) {
            this.node = n;
            this.target = t;
            this.prefix = p;
        }
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ret = new ArrayList<>();
        if (root == null)
            return ret;
        Stack<Context> stack = new Stack<>();
        stack.push(new Context(root, targetSum, List.of()));
        while (!stack.empty()) {
            Context ctx = stack.pop();
            if (ctx != null) {
                if (ctx.node.left != null) {
                    List<Integer> lprefix = new ArrayList<>(ctx.prefix);
                    lprefix.add(ctx.node.val);
                    stack.push(new Context(ctx.node.left, ctx.target - ctx.node.val, lprefix));
                }
                if (ctx.node.right != null) {
                    List<Integer> rprefix = new ArrayList<>(ctx.prefix);
                    rprefix.add(ctx.node.val);
                    stack.push(new Context(ctx.node.right, ctx.target - ctx.node.val, rprefix));
                }
                stack.push(ctx);
                stack.push(null);
            } else {
                ctx = stack.pop();
                if (ctx.node.left == null && ctx.node.right == null && ctx.node.val == ctx.target) {
                    List<Integer> path = new ArrayList<>(ctx.prefix);
                    path.add(ctx.node.val);
                    ret.add(path);
                }
            }
        }
        return ret;
    }
}
// @lc code=end
