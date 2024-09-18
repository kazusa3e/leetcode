/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 */

// @lc code=start

#include <functional>
#include <condition_variable>
#include <mutex>

using namespace std;

class H2O {
private:
    int num_hydrogen {0};
    int num_oxygen {0};
    mutex mtx;
    condition_variable cv;

public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck {mtx};
        cv.wait(lck, [&] { return (num_hydrogen < 2 * (num_oxygen + 1)); });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        num_hydrogen += 1;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck {mtx};
        cv.wait(lck, [&] { return (num_oxygen < num_hydrogen / 2); });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        num_oxygen += 1;
        cv.notify_all();
    }
};
// @lc code=end
