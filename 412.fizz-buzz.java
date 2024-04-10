/*
 * @lc app=leetcode id=412 lang=java
 *
 * [412] Fizz Buzz
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ret = new ArrayList<>();
        for (int ix = 1; ix != n + 1; ++ix) {
            if (ix % 15 == 0) ret.add("FizzBuzz");
            else if (ix % 3 == 0) ret.add("Fizz");
            else if (ix % 5 == 0) ret.add("Buzz");
            else ret.add(String.valueOf(ix));
        }
        return ret;
    }
}
// @lc code=end

