/*
 * @lc app=leetcode id=1051 lang=java
 *
 * [1051] Height Checker
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int heightChecker(int[] heights) {
        List<Integer> expected = new ArrayList<>();
        for (int n : heights) expected.add(n);
        Collections.sort(expected);
        int cnt = 0;
        for (int ix = 0; ix != heights.length; ++ix) {
            if (heights[ix] != expected.get(ix)) cnt += 1;
        }
        return cnt;
    }
}
// @lc code=end

