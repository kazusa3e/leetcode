/*
 * @lc app=leetcode id=617 lang=java
 *
 * [617] Merge Two Binary Trees
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

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
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null) return root2;
        if (root2 == null) return root1;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root1); queue.add(root2);
        while (!queue.isEmpty()) {
            TreeNode n1 = queue.remove();
            TreeNode n2 = queue.remove();
            n1.val += n2.val;
            if (n1.left == null) n1.left = n2.left;
            else if (n1.left != null && n2.left != null) {
                queue.add(n1.left); queue.add(n2.left);
            }
            if (n1.right == null) n1.right = n2.right;
            else if (n1.right != null && n2.right != null) {
                queue.add(n1.right); queue.add(n2.right);
            }
        }
        return root1;
    }
}
// @lc code=end
