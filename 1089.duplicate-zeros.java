/*
 * @lc app=leetcode id=1089 lang=java
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
    public void duplicateZeros(int[] arr) {
        int zeros = 0;
        for (int n : arr) {
            if (n == 0)
                zeros += 1;
        }
        int[] tmp = new int[arr.length + zeros];
        int idx = 0;
        for (int n : arr) {
            if (n == 0) {
                tmp[idx++] = n;
            }
            tmp[idx++] = n;
        }
        for (int ix = 0; ix != arr.length; ++ix) {
            arr[ix] = tmp[ix];
        }
    }
}
// @lc code=end
