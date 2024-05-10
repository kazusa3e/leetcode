/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start

#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s1_;
    stack<int> s2_;

public:
    MyQueue() {
    }

    void push(int x) {
        s1_.push(x);
    }

    int pop() {
        if (s2_.empty()) {
            while (!s1_.empty()) {
                int x = s1_.top();
                s2_.push(x);
                s1_.pop();
            }
        }
        int ret = s2_.top();
        s2_.pop();
        return ret;
    }

    int peek() {
        if (s2_.empty()) {
            while (!s1_.empty()) {
                int x = s1_.top();
                s2_.push(x);
                s1_.pop();
            }
        }
        return s2_.top();
    }

    bool empty() {
        return s1_.empty() && s2_.empty();
    }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
