/*
 * @lc app=leetcode id=101 lang=java
 *
 * [101] Symmetric Tree
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root.left);
        queue.add(root.right);
        while (!queue.isEmpty()) {
            TreeNode lnode = queue.remove();
            TreeNode rnode = queue.remove();
            if (lnode == null && rnode == null)
                continue;
            if (lnode == null ^ rnode == null)
                return false;
            if (lnode.val != rnode.val)
                return false;
            queue.add(lnode.left);
            queue.add(rnode.right);
            queue.add(lnode.right);
            queue.add(rnode.left);
        }
        return true;
    }
}
// @lc code=end
