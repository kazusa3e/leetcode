/*
 * @lc app=leetcode id=17 lang=java
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

class Solution {
    private List<String> results;
    private StringBuilder letters;
    private Map<Character, List<Character>> map = Map.of(
            '2', List.of('a', 'b', 'c'),
            '3', List.of('d', 'e', 'f'),
            '4', List.of('g', 'h', 'i'),
            '5', List.of('j', 'k', 'l'),
            '6', List.of('m', 'n', 'o'),
            '7', List.of('p', 'q', 'r', 's'),
            '8', List.of('t', 'u', 'v'),
            '9', List.of('w', 'x', 'y', 'z'));

    public List<String> letterCombinations(String digits) {
        if (digits.equals("")) {
            return new ArrayList<>();
        }
        results = new ArrayList<>();
        letters = new StringBuilder(digits.length());
        backtracking(digits.toCharArray(), 0);
        return results;
    }

    private void backtracking(char[] digits, int startIndex) {
        if (letters.length() == digits.length) {
            results.add(letters.toString());
            return;
        }
        List<Character> chars = map.get(digits[startIndex]);
        for (char ch : chars) {
            letters.append(ch);
            backtracking(digits, startIndex + 1);
            letters.deleteCharAt(letters.length() - 1);
        }
    }
}
// @lc code=end
