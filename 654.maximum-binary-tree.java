/*
 * @lc app=leetcode id=654 lang=java
 *
 * [654] Maximum Binary Tree
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

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if (nums.length == 1)
            return new TreeNode(nums[0]);
        int delim = 0;
        int max = nums[0];
        for (int ix = 1; ix != nums.length; ++ix) {
            if (nums[ix] > max) {
                max = nums[ix];
                delim = ix;
            }
        }
        TreeNode root = new TreeNode(nums[delim]);
        if (delim != 0) {
            int[] left = Arrays.copyOfRange(nums, 0, delim);
            root.left = constructMaximumBinaryTree(left);
        }
        if (delim + 1 != nums.length) {
            int[] right = Arrays.copyOfRange(nums, delim + 1, nums.length);
            root.right = constructMaximumBinaryTree(right);
        }
        return root;
    }
}
// @lc code=end
