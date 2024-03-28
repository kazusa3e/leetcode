/*
 * @lc app=leetcode id=1431 lang=java
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = Arrays.stream(candies).max().orElse(-1);
        List<Boolean> ret = new ArrayList<>();
        for (int ix = 0; ix != candies.length; ++ix) {
            ret.add(candies[ix] + extraCandies >= max);
        }
        return ret;
    }
}
// @lc code=end
