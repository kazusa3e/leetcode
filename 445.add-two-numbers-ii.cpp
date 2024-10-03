/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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

#include <deque>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        deque<unsigned> d1, d2;
        while (l1 != nullptr) {
            d1.push_back(l1->val); l1 = l1->next;
        }
        while (l2 != nullptr) {
            d2.push_back(l2->val); l2 = l2->next;
        }

        ListNode tmp, *dummy = &tmp;
        unsigned carry = 0;
        while (!d1.empty() && !d2.empty()) {
            unsigned val = d1.back() + d2.back() + carry;
            carry = 0;
            ListNode *h = dummy->next;
            ListNode *n = new ListNode(val % 10, h);
            dummy->next = n;
            carry = (val >= 10) ? 1 : 0;
            d1.pop_back(); d2.pop_back();
        }
        while (!d1.empty()) {
            unsigned val = d1.back() + carry;
            carry = 0;
            ListNode *h = dummy->next;
            ListNode *n = new ListNode(val % 10, h);
            dummy->next = n;
            carry = (val >= 10) ? 1 : 0;
            d1.pop_back();
        }
        while (!d2.empty()) {
            unsigned val = d2.back() + carry;
            carry = 0;
            ListNode *h = dummy->next;
            ListNode *n = new ListNode(val % 10, h);
            dummy->next = n;
            carry = (val >= 10) ? 1 : 0;
            d2.pop_back();
        }
        if (carry) {
            ListNode *h = dummy->next;
            ListNode *n = new ListNode(1, h);
            dummy->next = n;
        }
        return dummy->next;
    }
};
// @lc code=end
