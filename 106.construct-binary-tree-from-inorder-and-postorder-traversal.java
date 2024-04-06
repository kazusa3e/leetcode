/*
 * @lc app=leetcode id=106 lang=java
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start

import java.util.Arrays;

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0)
            return null;
        if (inorder.length == 1)
            return new TreeNode(inorder[0]);
        TreeNode root = new TreeNode(postorder[postorder.length - 1]);
        int idx = 0;
        for (int ix = 0; ix != inorder.length; ++ix) {
            if (inorder[ix] == postorder[postorder.length - 1]) {
                idx = ix;
            }
        }
        int[] leftInorder = Arrays.copyOfRange(inorder, 0, idx);
        int[] rightInorder = Arrays.copyOfRange(inorder, idx + 1, inorder.length);
        int[] leftPostorder = Arrays.copyOfRange(postorder, 0, leftInorder.length);
        int[] rightPostorder = Arrays.copyOfRange(postorder, leftPostorder.length, postorder.length - 1);
        root.left = buildTree(leftInorder, leftPostorder);
        root.right = buildTree(rightInorder, rightPostorder);
        return root;
    }
}
// @lc code=end
