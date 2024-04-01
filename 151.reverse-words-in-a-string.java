/*
 * @lc app=leetcode id=151 lang=java
 *
 * [151] Reverse Words in a String
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

class Solution {

    public String reverseWords(String s) {
        List<String> words = new ArrayList<String>(
                Arrays.asList(s.trim().split("\\s")))
                .stream().filter(x -> x != "")
                .collect(Collectors.toList());
        Collections.reverse(words);
        return String.join(" ", words);
    }
}
// @lc code=end
