/*
 * @lc app=leetcode id=236 lang=java
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private static class Context {
        TreeNode node;
        List<TreeNode> prefix;
        public Context(TreeNode node, List<TreeNode> prefix) {
            this.node = node;
            this.prefix = prefix;
        }
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> ppath = null, qpath = null;
        Stack<Context> stack = new Stack<>();
        stack.push(new Context(root, new ArrayList<>()));
        while (!stack.empty()) {
            Context ctx = stack.pop();
            if (ctx != null) {
                TreeNode node = ctx.node; List<TreeNode> prefix = new ArrayList<>(ctx.prefix);
                prefix.add(node);
                if (node.right != null) stack.push(new Context(node.right, prefix));
                if (node.left != null) stack.push(new Context(node.left, prefix));
                stack.push(ctx); stack.push(null);
            } else {
                ctx = stack.pop();
                TreeNode node = ctx.node; List<TreeNode> prefix = new ArrayList<>(ctx.prefix);
                prefix.add(node);
                if (node.val == p.val) ppath = prefix;
                if (node.val == q.val) qpath = prefix;
            }
        }
        TreeNode iter = null;
        for (int ix = 0; ix != Math.min(ppath.size(), qpath.size()); ++ix) {
            if (ppath.get(ix).val == qpath.get(ix).val) {
                iter = ppath.get(ix);
            } else break;
        }
        return iter;
    }
}
// @lc code=end
