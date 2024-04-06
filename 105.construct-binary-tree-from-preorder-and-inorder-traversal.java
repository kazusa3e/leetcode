/*
 * @lc app=leetcode id=105 lang=java
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0)
            return null;
        TreeNode root = new TreeNode(preorder[0]);
        if (preorder.length == 1)
            return root;
        int delim = -1;
        for (int ix = 0; ix != inorder.length; ++ix) {
            if (inorder[ix] == preorder[0])
                delim = ix;
        }
        int[] leftInorder = Arrays.copyOfRange(inorder, 0, delim);
        int[] rightInorder = Arrays.copyOfRange(inorder, delim + 1, inorder.length);
        int[] leftPreorder = Arrays.copyOfRange(preorder, 1, leftInorder.length + 1);
        int[] rightPreorder = Arrays.copyOfRange(preorder, 1 + leftPreorder.length, preorder.length);
        root.left = buildTree(leftPreorder, leftInorder);
        root.right = buildTree(rightPreorder, rightInorder);
        return root;
    }
}
// @lc code=end
