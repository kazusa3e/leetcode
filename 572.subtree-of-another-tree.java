/*
 * @lc app=leetcode id=572 lang=java
 *
 * [572] Subtree of Another Tree
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
    private boolean isSame(TreeNode a, TreeNode b) {
        if (a == null && b == null)
            return true;
        if (a == null ^ b == null)
            return false;
        if (a.val != b.val)
            return false;
        return isSame(a.left, b.left) && isSame(a.right, b.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null && subRoot == null)
            return true;
        if (subRoot == null)
            return true;
        if (root == null)
            return false;
        return isSame(root, subRoot)
                || isSubtree(root.left, subRoot)
                || isSubtree(root.right, subRoot);
    }
}
// @lc code=end
