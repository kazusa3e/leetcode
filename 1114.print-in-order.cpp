/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start

#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo {
public:
    Foo() { }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        is_first_done_ = true;
        cv_.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lck{mtx_};
        cv_.wait(lck, [&] { return is_first_done_; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        is_second_done_ = true;
        cv_.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck{mtx_};
        cv_.wait(lck, [&] { return is_second_done_; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    bool is_first_done_ {false};
    bool is_second_done_ {false};
    std::condition_variable cv_;
    std::mutex mtx_;
};
// @lc code=end
