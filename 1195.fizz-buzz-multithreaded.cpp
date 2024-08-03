/*
 * @lc app=leetcode id=1195 lang=cpp
 *
 * [1195] Fizz Buzz Multithreaded
 */

// @lc code=start

#include <functional>
#include <mutex>
#include <condition_variable>

enum class state { FIZZ, BUZZ, FIZZBUZZ, NUM };

using namespace std;

class FizzBuzz {
private:
    int n;
    int ix;
    state s;
    std::mutex mtx;
    std::condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->ix = 1;
        this->s = state::NUM;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            std::unique_lock<std::mutex> lck {mtx};
            cv.wait(lck, [&] { return ix > n || this->s == state::FIZZ; });
            if (ix > n) break;
            printFizz();
            ix += 1;
            if (ix % 15 == 0) s = state::FIZZBUZZ;
            else if (ix % 3 == 0) s = state::FIZZ;
            else if (ix % 5 == 0) s = state::BUZZ;
            else s = state::NUM;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lck {mtx};
            cv.wait(lck, [&] { return ix > n || this->s == state::BUZZ; });
            if (ix > n) break;
            printBuzz();
            ix += 1;
            if (ix % 15 == 0) s = state::FIZZBUZZ;
            else if (ix % 3 == 0) s = state::FIZZ;
            else if (ix % 5 == 0) s = state::BUZZ;
            else s = state::NUM;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lck {mtx};
            cv.wait(lck, [&] { return ix > n || this->s == state::FIZZBUZZ; });
            if (ix > n) break;
            printFizzBuzz();
            ix += 1;
            if (ix % 15 == 0) s = state::FIZZBUZZ;
            else if (ix % 3 == 0) s = state::FIZZ;
            else if (ix % 5 == 0) s = state::BUZZ;
            else s = state::NUM;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck {mtx};
            cv.wait(lck, [&] { return ix > n || this->s == state::NUM; });
            if (ix > n) break;
            printNumber(ix);
            ix += 1;
            if (ix % 15 == 0) s = state::FIZZBUZZ;
            else if (ix % 3 == 0) s = state::FIZZ;
            else if (ix % 5 == 0) s = state::BUZZ;
            else s = state::NUM;
            cv.notify_all();
        }
    }
};
// @lc code=end
