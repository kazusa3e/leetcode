/*
 * @lc app=leetcode id=232 lang=java
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start

import java.util.Stack;

class MyQueue {

    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public MyQueue() {
        this.stack1 = new Stack<>();
        this.stack2 = new Stack<>();
    }

    public void push(int x) {
        this.stack1.push(x);
    }

    public int pop() {
        if (this.stack2.empty()) {
            while (!this.stack1.empty()) {
                this.stack2.push(this.stack1.pop());
            }
        }
        if (this.stack2.empty()) {
            return -1;
        }
        return this.stack2.pop();
    }

    public int peek() {
        if (this.stack2.empty()) {
            while (!this.stack1.empty()) {
                this.stack2.push(this.stack1.pop());
            }
        }
        if (this.stack2.empty()) {
            return -1;
        }
        return this.stack2.peek();
    }

    public boolean empty() {
        return this.stack1.empty() && this.stack2.empty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
// @lc code=end
