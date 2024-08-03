/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 */

// @lc code=start

#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool turn;

public:
    FooBar(int n) {
        this->n = n;
        this->turn = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck {this->mtx};
            cv.wait(lck, [&] { return this->turn == false; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            this->turn = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lck {this->mtx};
            cv.wait(lck, [&] { return this->turn == true; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            this->turn = false;
            cv.notify_one();
        }
    }
};
// @lc code=end
