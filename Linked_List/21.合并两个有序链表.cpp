/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
                ListNode *head = nullptr, *tail = nullptr;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (head == nullptr) {
                    head = tail = list1;
                } else {
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = list1->next;
            } else {
                if (head == nullptr) {
                    head = tail = list2;
                } else {
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = list2->next;
            }
        }

        if (list1) {
            if (head == nullptr) {
                head = list1;
            } else {
                tail->next = list1;
            }
        }

        if (list2) {
            if (head == nullptr) {
                head = list2;
            } else {
                tail->next = list2;
            }
        }

        return head;
    }
};
// @lc code=end

