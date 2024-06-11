/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto tmp = slow->next;
        slow->next = nullptr;
        head = sortList(head); tmp = sortList(tmp);
        ListNode dummy {-1};
        auto tail = &dummy;
        auto i1 = head, i2 = tmp;
        while (i1 != nullptr && i2 != nullptr) {
            if (i1->val < i2->val) {
                tail->next = i1;
                i1 = i1->next;
                tail = tail->next;
            } else {
                tail->next = i2;
                i2 = i2->next;
                tail = tail->next;
            }
        }
        while (i1 != nullptr) {
            tail->next = i1;
            i1 = i1->next;
            tail = tail->next;
        }
        while (i2 != nullptr) {
            tail->next = i2;
            i2 = i2->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end
