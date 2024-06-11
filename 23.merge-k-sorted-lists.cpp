/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto pos = copy_if(lists.begin(), lists.end(), lists.begin(), [&](const ListNode * node) {
            return node != nullptr;
        });
        lists.erase(pos, lists.end());
        if (lists.size() == 0) return nullptr;
        ListNode dummy {-1};
        ListNode *tail = &dummy;
        while (lists.size() != 0) {
            auto m = min_element(lists.begin(), lists.end(), [&](const ListNode *a, const ListNode *b) {
                return a->val < b->val;
            });
            tail->next = *m;
            tail = tail->next;
            (*m) = (*m)->next;
            tail->next = nullptr;
            if (*m == nullptr) lists.erase(m);
        }
        return dummy.next;
    }
};
// @lc code=end
