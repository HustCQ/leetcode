/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
        ListNode *head, *tail;
        int sum = 0;
        int up = 0;
        head = tail = nullptr;

        while (l1 && l2) {
            sum = l1->val + l2->val + up;
            up = sum / 10;
            sum %= 10;

            if (head == nullptr) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            sum = l1->val + up;
            up = sum / 10;
            sum %= 10;
            if (head == nullptr) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            l1 = l1->next;
        }

        while (l2) {
            sum = l2->val + up;
            up = sum / 10;
            sum %= 10;
            if (head == nullptr) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            l2 = l2->next;
        }

        if (up != 0) {
            tail->next = new ListNode(up);
        }

        return head;
    }
};
// @lc code=end

