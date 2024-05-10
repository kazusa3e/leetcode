/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> queue_;
public:
    MyStack() {
    }

    void push(int x) {
        queue_.push(x);
    }

    int pop() {
        auto sz = queue_.size() - 1;
        while (sz != 0) {
            int x = queue_.front();
            queue_.pop();
            queue_.push(x);
            sz -= 1;
        }
        int ret = queue_.front();
        queue_.pop();
        return ret;
    }

    int top() {
        auto sz = queue_.size() - 1;
        while (sz != 0) {
            int x = queue_.front();
            queue_.pop();
            queue_.push(x);
            sz -= 1;
        }
        int ret = queue_.front();
        queue_.pop();
        queue_.push(ret);
        return ret;
    }

    bool empty() {
        return queue_.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
