/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename Iterator,
    typename Comparator = std::less<typename std::iterator_traits<Iterator>::value_type>,
    typename = typename std::enable_if_t<
        std::is_convertible_v<decltype(std::declval<Comparator>()(
            std::declval<typename std::iterator_traits<Iterator>::value_type>(),
            std::declval<typename std::iterator_traits<Iterator>::value_type>()
        )), bool>
    >
>
void quick_sort(Iterator begin, Iterator end,
    Comparator comp = Comparator()) {
    if (begin >= end) return;
    std::swap(*begin, *(begin + rand() % (end - begin)));
    auto pivot = *begin; auto left = begin + 1, right = end - 1;
    while (left <= right) {
        while (left <= right && comp(*left, pivot)) ++left;
        while (left <= right && !comp(*right, pivot)) --right;
        if (left < right) std::swap(*left++, *right--);
    }
    std::swap(*begin, *right);
    quick_sort(begin, right, comp); quick_sort(right + 1, end, comp);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end
