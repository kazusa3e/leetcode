/*
 * @lc app=leetcode id=1295 lang=java
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
    private int digits(int x) {
        int ret = 0;
        while (x != 0) {
            ret += 1;
            x /= 10;
        }
        return ret;
    }

    public int findNumbers(int[] nums) {
        int cnt = 0;
        for (int ix = 0; ix != nums.length; ++ix) {
            if (digits(nums[ix]) % 2 == 0)
                cnt += 1;
        }
        return cnt;
    }
}
// @lc code=end
