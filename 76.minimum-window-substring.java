/*
 * @lc app=leetcode id=76 lang=java
 *
 * [76] Minimum Window Substring
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    private static boolean contains(Map<Character, Integer> s, Map<Character, Integer> t) {
        if (!s.keySet().containsAll(t.keySet())) {
            return false;
        }
        for (char ch : t.keySet()) {
            if (s.get(ch) < t.get(ch)) {
                return false;
            }
        }
        return true;
    }

    public String minWindow(String s, String t) {
        if (s.length() < t.length()) {
            return "";
        }
        Map<Character, Integer> patternMap = new HashMap<>();
        for (char ch : t.toCharArray()) {
            patternMap.put(ch, patternMap.getOrDefault(ch, 0) + 1);
        }
        Map<Character, Integer> smap = new HashMap<>();
        int substrLen = Integer.MAX_VALUE;
        int substrStarts = 0;
        for (int left = 0, right = 0; right != s.length(); ++right) {
            smap.put(s.charAt(right), smap.getOrDefault(s.charAt(right), 0) + 1);
            while (contains(smap, patternMap)) {
                if (right - left + 1 < substrLen) {
                    substrLen = right - left + 1;
                    substrStarts = left;
                }
                smap.put(s.charAt(left), smap.getOrDefault(s.charAt(left), 0) - 1);
                smap.remove(s.charAt(left), 0);
                left += 1;
            }
        }
        if (substrLen == Integer.MAX_VALUE) {
            return "";
        }
        return s.substring(substrStarts, substrStarts + substrLen);
    }
}
// @lc code=end
