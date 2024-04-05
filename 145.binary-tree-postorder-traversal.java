/*
 * @lc app=leetcode id=145 lang=java
 *
 * [145] Binary Tree Postorder Traversal
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
    private void postorderTraversal(TreeNode root, List<Integer> lst) {
        if (root == null)
            return;
        postorderTraversal(root.left, lst);
        postorderTraversal(root.right, lst);
        lst.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> lst = new ArrayList<>();
        postorderTraversal(root, lst);
        return lst;
    }
}
// @lc code=end
