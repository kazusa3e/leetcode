/*
 * @lc app=leetcode id=1299 lang=java
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
    public int[] replaceElements(int[] arr) {
        if (arr.length == 1) return new int[] { -1 };
        int max = -1;
        for (int ix = arr.length - 1; ix != -1; --ix) {
            int tmp = arr[ix];
            arr[ix] = max;
            max = Math.max(tmp, max);
        }
        return arr;
    }
}
// @lc code=end

