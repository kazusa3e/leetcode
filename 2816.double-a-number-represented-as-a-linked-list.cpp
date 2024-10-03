/*
 * @lc app=leetcode id=2816 lang=cpp
 *
 * [2816] Double a Number Represented as a Linked List
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
    ListNode* doubleIt(ListNode* head) {
        deque<unsigned> digits;
        while (head != nullptr) {
            digits.push_back(head->val); head = head->next;
        }
        ListNode tmp, *dummy = &tmp;
        auto insert = [&dummy](unsigned x) -> void {
            ListNode *h = dummy->next;
            dummy->next = new ListNode(x, h);
        };
        unsigned carry = 0;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            unsigned val = (*iter) * 2 + carry;
            carry = val / 10;
            insert(val % 10);
        }
        if (carry) insert(1);
        return dummy->next;
    }
};
// @lc code=end
