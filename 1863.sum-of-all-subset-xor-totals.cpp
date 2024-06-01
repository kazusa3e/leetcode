/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start

#include <vector>
#include <functional>
#include <numeric>

using namespace std;

template <typename T>
void subset(const vector<T> &elements, function<void(const vector<T> &)> callback) {
    vector<T> bag;
    function<void(const typename vector<T>::const_iterator &)> backtracking;
    backtracking = [&](const typename vector<T>::const_iterator &pos) {
        callback(bag);
        if (pos == elements.end()) return;
        for (auto iter = pos; iter != elements.end(); ++iter) {
            bag.push_back(*iter);
            backtracking(iter + 1);
            bag.pop_back();
        }
    };
    backtracking(elements.begin());
}

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        subset<int>(nums, [&](const vector<int> &m_set) {
            int res = accumulate(m_set.begin(), m_set.end(), 0.0, [](int a, int b) {
                return a ^ b;
            });
            sum += res;
        });
        return sum;
    }
};
// @lc code=end
