/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;

        auto ret = ListNode {-1};
        auto tail = &ret;
        auto append = [&](int val) {
            tail->next = new ListNode {val};
            tail = tail->next;
        };

        auto iter1 = l1, iter2 = l2;
        while (iter1 != nullptr && iter2 != nullptr) {
            int sum = iter1->val + iter2->val + ((carry) ? 1 : 0);
            carry = (sum >= 10);
            append(sum % 10);
            iter1 = iter1->next; iter2 = iter2->next;
        }
        while (iter1 != nullptr) {
            int sum = iter1->val + ((carry) ? 1 : 0);
            carry = (sum >= 10);
            append(sum % 10);
            iter1 = iter1->next;
        }
        while (iter2 != nullptr) {
            int sum = iter2->val + ((carry) ? 1 : 0);
            carry = (sum >= 10);
            append(sum % 10);
            iter2 = iter2->next;
        }
        if (carry) append(1);

        return ret.next;
    }
};
// @lc code=end
