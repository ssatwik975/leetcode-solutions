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
        if (!head || !head->next)
            return head; 

        ListNode* dummy = new ListNode(-1); 
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* one = prev->next;
            ListNode* two = one->next;

            one->next = two->next;
            two->next = one;
            prev->next = two;

            prev = one;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

