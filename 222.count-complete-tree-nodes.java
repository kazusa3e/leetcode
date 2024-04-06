/*
 * @lc app=leetcode id=222 lang=java
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
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
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        TreeNode liter = root.left, riter = root.right;
        int ldepth = 1, rdepth = 1;
        while (liter != null) {
            liter = liter.left;
            ldepth += 1;
        }
        while (riter != null) {
            riter = riter.right;
            rdepth += 1;
        }
        if (ldepth == rdepth)
            return (2 << (ldepth - 1)) - 1;
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
}
// @lc code=end
