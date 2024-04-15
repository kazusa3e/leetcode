/*
 * @lc app=leetcode id=1002 lang=java
 *
 * [1002] Find Common Characters
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> commonChars(String[] words) {
        List<String> ret = new ArrayList<>();
        if (words.length == 1) {
            for (char ch : words[0].toCharArray()) ret.add(String.valueOf(ch));
            return ret;
        }
        List<Map<Character, Integer>> maps = new ArrayList<>();
        for (String word : words) {
            maps.add(count(word));
        }
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            final char _ch = ch;
            int times = (int) maps.stream()
                .map(m -> m.getOrDefault(_ch, 0))
                .mapToInt(x -> x)
                .min().orElse(-1);
            while (times != 0) {
                ret.add(String.valueOf(ch));
                times -= 1;
            }
        }
        return ret;
    }
    private Map<Character, Integer> count(String s) {
        Map<Character, Integer> ret = new HashMap<>();
        for (char ch : s.toCharArray()) {
            ret.put(ch, ret.getOrDefault(ch, 0) + 1);
        }
        return ret;
    }
}
// @lc code=end

