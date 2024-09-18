/*
 * @lc app=leetcode id=1226 lang=cpp
 *
 * [1226] The Dining Philosophers
 */

// @lc code=start

#include <condition_variable>
#include <functional>
#include <mutex>
#include <array>

using namespace std;

class DiningPhilosophers {
private:
    mutex mtx;
    condition_variable cv;
    array<bool, 5> forks {true, true, true, true, true};

public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int l = philosopher, r = philosopher - 1;
        if (r == -1) r = 4;
        {
            unique_lock<mutex> lck {mtx};
            cv.wait(lck, [&] { return forks[l] && forks[r]; });
            pickLeftFork();
            forks[l] = false;
            pickRightFork();
            forks[r] = false;
        }
        eat();
        {
            unique_lock<mutex> lck {mtx};
            putLeftFork();
            forks[l] = true;
            cv.notify_one();
        }
        {
            unique_lock<mutex> lck {mtx};
            putRightFork();
            forks[r] = true;
            cv.notify_one();
        }
    }
};
// @lc code=end
