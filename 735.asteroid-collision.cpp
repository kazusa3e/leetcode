/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start

#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> st;
        for_each(asteroids.begin(), asteroids.end(), [&st](int val) {
            while (true) {
                if (st.empty()) { st.push_back(val); break; }
                else if (val * st.back() > 0) { st.push_back(val); break; }
                else if (val > 0 && st.back() < 0) { st.push_back(val); break; }
                else {
                    if (st.back() == -val) { st.pop_back(); break; }
                    if (st.back() > -val) { break; }
                    else { st.pop_back(); continue; }
                }
            }
        });
        return { st.begin(), st.end() };

    }
};
// @lc code=end
