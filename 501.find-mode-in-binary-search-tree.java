/*
 * @lc app=leetcode id=501 lang=java
 *
 * [501] Find Mode in Binary Search Tree
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
    public int[] findMode(TreeNode root) {
        int maxTimes = -1;
        int times = -1;
        List<Integer> ret = new ArrayList<>();
        TreeNode prev = null;
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
                if (prev != null) {
                    if (node.val == prev.val) times += 1;
                    else times = 1;
                    if (times == maxTimes) ret.add(node.val);
                    if (times > maxTimes) {
                        ret.clear();
                        ret.add(node.val);
                        maxTimes = times;
                    }
                } else {
                    ret.add(node.val); times = 1; maxTimes = 1;
                }
                prev = node;
            }
        }
        return ret.stream().mapToInt(x -> x).toArray();
    }
}
// @lc code=end

