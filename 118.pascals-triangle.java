/*
 * @lc app=leetcode id=118 lang=java
 *
 * [118] Pascal's Triangle
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        if (numRows == 1) {
            return List.of(List.of(1));
        }
        if (numRows == 2) {
            return List.of(
                    List.of(1), List.of(1, 1));
        }
        List<List<Integer>> above = new ArrayList<>(generate(numRows - 1));
        List<Integer> prev = above.get(above.size() - 1);
        List<Integer> lst = new ArrayList<>();
        lst.add(1);
        for (int ix = 0; ix != numRows - 2; ++ix) {
            lst.add(prev.get(ix) + prev.get(ix + 1));
        }
        lst.add(1);
        above.add(lst);
        return above;
    }
}
// @lc code=end
