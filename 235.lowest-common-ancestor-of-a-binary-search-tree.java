/*
 * @lc app=leetcode id=235 lang=java
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int min = Math.min(p.val, q.val), max = Math.max(p.val, q.val);
        if (root.val >= min && root.val <= max) return root;
        TreeNode lres = (root.left != null) ? lowestCommonAncestor(root.left, p, q) : null;
        TreeNode rres = (root.right != null) ? lowestCommonAncestor(root.right, p, q) : null;
        return (lres == null) ? rres : lres;
    }
}
// @lc code=end

