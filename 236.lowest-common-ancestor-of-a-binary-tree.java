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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (root.val == p.val) return p;
        if (root.val == q.val) return q;
        if (root.left == null && root.right == null) return null;
        if (root.left == null) return lowestCommonAncestor(root.right, p, q);
        if (root.right == null) return lowestCommonAncestor(root.left, p, q);
        TreeNode lres = lowestCommonAncestor(root.left, p, q);
        TreeNode rres = lowestCommonAncestor(root.right, p, q);
        if (lres != null && rres != null) return root;
        if (lres == null ^ rres == null)
            return (lres == null) ? rres : lres;
        return null;
    }
}
// @lc code=end
