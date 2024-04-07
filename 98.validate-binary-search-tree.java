/*
 * @lc app=leetcode id=98 lang=java
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

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
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        List<Integer> lst = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        stack.add(root);
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (node.right != null) stack.add(node.right);
                stack.add(node); stack.add(null);
                if (node.left != null) stack.add(node.left);
            } else {
                node = stack.pop();
                lst.add(node.val);
            }
        }
        Long min = Long.MIN_VALUE;
        for (int elem : lst) {
            if (elem <= min) return false;
            min = (long) elem;
        }
        return true;
    }
}
// @lc code=end

