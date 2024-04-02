/*
 * @lc app=leetcode id=225 lang=java
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Queue;

class MyStack {

    Queue<Integer> queue;

    public MyStack() {
        this.queue = new ArrayDeque<>();
    }

    public void push(int x) {
        this.queue.add(x);
    }

    public int pop() {
        for (int n = this.queue.size() - 1; n != 0; --n) {
            this.queue.add(this.queue.remove());
        }
        return this.queue.remove();
    }

    public int top() {
        for (int n = this.queue.size() - 1; n != 0; --n) {
            this.queue.add(this.queue.remove());
        }
        int ret = this.queue.remove();
        this.queue.add(ret);
        return ret;
    }

    public boolean empty() {
        return this.queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
// @lc code=end
