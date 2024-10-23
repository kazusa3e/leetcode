/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

class LRUCache {
public:
    unsigned caps;
    list<pair<int, int>> lst;   // k, v
    unordered_map<int, decltype(lst)::iterator> m;

public:
    LRUCache(int capacity): caps(capacity) {}
    
    int get(int key) {
        if (auto pos = m.find(key); pos != m.end()) {
            lst.splice(lst.begin(), lst, pos->second);
            return pos->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (auto pos = m.find(key); pos != m.end()) {
            lst.splice(lst.begin(), lst, pos->second);
            lst.front().second = value;
            return;
        }
        if (lst.size() != caps) {
            lst.insert(lst.begin(), make_pair(key, value));
            m[key] = lst.begin();
            return;
        }
        auto kv = lst.back();
        lst.pop_back();
        m.erase(kv.first);
        lst.insert(lst.begin(), make_pair(key, value));
        m[key] = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
