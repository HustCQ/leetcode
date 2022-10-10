/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;
        ListNode *sentinel = new ListNode(0, head);
        ListNode *p = sentinel, *q = sentinel;
        ++n;
        while (n--) {
            q = q->next;
        }

        while (p && q) {
            p = p->next;
            q = q->next;
        }

        q = p->next;
        p->next = q->next;
        delete q;

        head = sentinel->next;
        delete sentinel;

        return head;
    }
};
// @lc code=end

