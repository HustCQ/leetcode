/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    void swap(vector<ListNode*> &array, int i, int j) {
        ListNode* p = array[i];
        array[i] = array[j];
        array[j] = p;
    }

    ListNode* swapPairs(ListNode* head) {

        if (!head || !head->next) return head;

        vector<ListNode*> array;

        while (head) {
            ListNode *p = head;
            head = head->next;
            p->next = nullptr;
            array.push_back(p);
        }

        for(int i = 0; i < array.size()-1; i += 2) {
            swap(array, i, i +1);
        }

        for (int i = 0; i < array.size()-1; i++) {
            array[i]->next = array[i+1];
        }

        return *array.begin();
    }
};
// @lc code=end

