/*
 * @lc app=leetcode id=242 lang=java
 *
 * [242] Valid Anagram
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public boolean isAnagram(String s, String t) {
        int[] map = new int[26];
        for (char ch : s.toCharArray()) {
            map[ch - 'a'] += 1;
        }
        for (char ch : t.toCharArray()) {
            map[ch - 'a'] -= 1;
        }
        return (Arrays.stream(map)
                .filter(x -> x != 0)
                .count() == 0);
    }
}
// @lc code=end
