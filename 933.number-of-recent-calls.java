/*
 * @lc app=leetcode id=933 lang=java
 *
 * [933] Number of Recent Calls
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Queue;

class RecentCounter {

    private Queue<Integer> queue;
    private static final int DURATION = 3000;

    public RecentCounter() {
        this.queue = new ArrayDeque<>();
    }
    
    public int ping(int t) {
        this.queue.add(t);
        int limit = t - DURATION;
        while (!this.queue.isEmpty() && this.queue.peek() < limit) {
            this.queue.remove();
        }
        return this.queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
// @lc code=end

