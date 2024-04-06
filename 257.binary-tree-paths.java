/*
 * @lc app=leetcode id=257 lang=java
 *
 * [257] Binary Tree Paths
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> path = new ArrayList<>();
        if (root == null)
            return path;
        if (root.left == null && root.right == null) {
            return List.of(String.valueOf(root.val));
        }
        if (root.left != null) {
            List<String> leftPath = binaryTreePaths(root.left);
            for (String p : leftPath) {
                path.add(root.val + "->" + p);
            }
        }
        if (root.right != null) {
            List<String> rightPath = binaryTreePaths(root.right);
            for (String p : rightPath) {
                path.add(root.val + "->" + p);
            }
        }
        return path;
    }
}
// @lc code=end
