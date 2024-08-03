/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start

#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

enum class state { zero, even, odd };

class ZeroEvenOdd {
private:
    int n;
    state s;
    std::mutex mtx;
    std::condition_variable cv;
    int ix;
    bool done;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->s = state::zero;
        this->ix = 1;
        this->done = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck {this->mtx};
            this->cv.wait(lck, [&] { return done || this->s == state::zero; });
            if (done) break;
            printNumber(0);
            this->s = ((this->ix % 2 == 1) ? state::odd : state::even);
            this->cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck {this->mtx};
            this->cv.wait(lck, [&] { return done || this->s == state::even; });
            if (done) break;
            printNumber(this->ix);
            this->ix += 1;
            this->s = state::zero;
            this->done = (ix > this->n);
            this->cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck {this->mtx};
            this->cv.wait(lck, [&] { return done || this->s == state::odd; });
            if (done) break;
            printNumber(this->ix);
            this->ix += 1;
            this->s = state::zero;
            this->done = (ix > this->n);
            this->cv.notify_all();
        }
    }
};
// @lc code=end
