/*
 * @lc app=leetcode id=144 lang=java
 *
 * [144] Binary Tree Preorder Traversal
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
    private void preorderTraversal(TreeNode root, List<Integer> lst) {
        if (root == null)
            return;
        lst.add(root.val);
        preorderTraversal(root.left, lst);
        preorderTraversal(root.right, lst);
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> lst = new ArrayList<>();
        preorderTraversal(root, lst);
        return lst;
    }
}
// @lc code=end
