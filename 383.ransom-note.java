/*
 * @lc app=leetcode id=383 lang=java
 *
 * [383] Ransom Note
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] records = new int[26];
        for (char ch : magazine.toCharArray()) {
            records[ch - 'a'] += 1;
        }
        for (char ch : ransomNote.toCharArray()) {
            records[ch - 'a'] -= 1;
        }
        return Arrays.stream(records)
                .filter(x -> x < 0)
                .count() == 0;
    }
}
// @lc code=end
