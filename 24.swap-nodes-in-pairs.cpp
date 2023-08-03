/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* prev = head, *cur = head -> next, *res = head -> next;

        while (true)
        {
            prev -> next = cur -> next;
            cur -> next = prev;
            ListNode* tmp = prev -> next;
            if (tmp == nullptr)
                break;
            cur = tmp -> next;
            if (cur == nullptr)
                break;
            prev -> next = cur;
            prev = tmp;
        }

        return res;
    }
};
// @lc code=end

