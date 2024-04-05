/*
 * @lc app=leetcode id=347 lang=java
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start

import java.util.AbstractMap;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> frequence = new HashMap<>();
        for (int n : nums) {
            frequence.put(n, frequence.getOrDefault(n, 0) + 1);
        }
        PriorityQueue<AbstractMap.SimpleEntry<Integer, Integer>> pq = new PriorityQueue<>(
                (a, b) -> a.getValue() - b.getValue());
        for (Map.Entry<Integer, Integer> entry : frequence.entrySet()) {
            pq.add(new AbstractMap.SimpleEntry<Integer, Integer>(entry.getKey(), entry.getValue()));
            if (pq.size() > k) {
                pq.remove();
            }
        }
        int[] ret = new int[k];
        while (k > 0) {
            ret[--k] = pq.remove().getKey();
        }
        return ret;
    }
}
// @lc code=end
