/*
 * @lc app=leetcode id=2942 lang=java
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> ret = new ArrayList<>();
        for (int ix = 0; ix != words.length; ++ix) {
            if (words[ix].indexOf(x) != -1) {
                ret.add(ix);
            }
        }
        return ret;
    }
}
// @lc code=end
