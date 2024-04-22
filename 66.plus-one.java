/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int[] plusOne(int[] digits) {
        if (Arrays.stream(digits).allMatch(x -> x == 9)) {
            int[] ret = new int[digits.length + 1];
            ret[0] = 1;
            return ret;
        }
        plusOne(digits, digits.length - 1);
        return digits;
    }
    private void plusOne(int[] digits, int start) {
        if (digits[start] == 9) {
            digits[start] = 0;
            plusOne(digits, start - 1);
        } else {
            digits[start] += 1;
        }
    }
}
// @lc code=end

