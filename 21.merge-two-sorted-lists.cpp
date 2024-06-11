/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy {-1};
        ListNode *tail = &dummy;
        auto i1 = list1, i2 = list2;
        auto append = [&](int val) {
            tail->next = new ListNode {val};
            tail = tail->next;
        };
        while (i1 != nullptr && i2 != nullptr) {
            if (i1->val < i2->val) {
                append(i1->val);
                i1 = i1->next;
            } else {
                append(i2->val);
                i2 = i2->next;
            }
        }
        while (i1 != nullptr) {
            append(i1->val);
            i1 = i1->next;
        }
        while (i2 != nullptr) {
            append(i2->val);
            i2 = i2->next;
        }
        return dummy.next;
    }
};
// @lc code=end
