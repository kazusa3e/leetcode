/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start

#include <vector>
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    set<int> pq;
    unsigned base {1};

public:
    SmallestInfiniteSet() { }
    
    int popSmallest() {
        if (pq.empty()) return base++;
        if (*pq.begin() < base) {
            auto ret = *pq.begin(); pq.erase(pq.begin());
            return ret;
        }
        return base++;
    }
    
    void addBack(int num) {
        if (base > num) pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
