/*
 * @lc app=leetcode id=701 lang=java
 *
 * [701] Insert into a Binary Search Tree
 */

// @lc code=start
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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        TreeNode parent = null, iter = root;
        while (iter != null) {
            if (val < iter.val) {
                parent = iter; iter = iter.left;
            } else if (val > iter.val) {
                parent = iter; iter = iter.right;
            }
        }
        if (val < parent.val) parent.left = new TreeNode(val);
        if (val > parent.val) parent.right = new TreeNode(val);
        return root;
    }
}
// @lc code=end

