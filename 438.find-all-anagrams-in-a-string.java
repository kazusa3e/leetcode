/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if (s.length() < p.length()) {
            return new ArrayList<Integer>();
        }
        Map<Character, Integer> expected = new HashMap<>();
        for (char ch : p.toCharArray()) {
            expected.put(ch, expected.getOrDefault(ch, 0) + 1);
        }
        Map<Character, Integer> win = new HashMap<>();
        int ix = 0;
        char[] chars = s.toCharArray();
        while (ix != p.length()) {
            win.put(chars[ix], win.getOrDefault(chars[ix], 0) + 1);
            ix += 1;
        }
        List<Integer> ret = new ArrayList<>();
        if (win.equals(expected)) {
            ret.add(ix - p.length());
        }
        while (ix != chars.length) {
            win.put(chars[ix], win.getOrDefault(chars[ix], 0) + 1);
            win.put(chars[ix - p.length()], win.get(chars[ix - p.length()]) - 1);
            win.remove(chars[ix - p.length()], 0);
            if (win.equals(expected)) {
                ret.add(ix - p.length() + 1);
            }
            ix += 1;
        }
        return ret;
    }
}
// @lc code=end
