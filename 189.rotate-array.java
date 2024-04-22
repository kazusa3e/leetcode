/*
 * @lc app=leetcode id=189 lang=java
 *
 * [189] Rotate Array
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public void rotate(int[] nums, int k) {
        Deque<Integer> deque = new ArrayDeque<>();
        for (int n : nums)
            deque.add(n);
        for (int ix = 0; ix != k; ++ix) {
            deque.addFirst(deque.removeLast());
        }
        for (int ix = 0; ix != nums.length; ++ix) {
            nums[ix] = deque.removeFirst();
        }
    }
}
// @lc code=end
