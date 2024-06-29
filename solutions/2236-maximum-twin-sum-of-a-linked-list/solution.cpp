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
    ListNode* reversell(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* front = head;
        while (temp) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* tort = head;
        ListNode* hare = head;
        while (hare && hare->next) {
            tort = tort->next;
            hare = hare->next->next;
        }

        hare = reversell(tort);
        tort = head;

        int maxSum = 0;
        while (hare) {
            maxSum = max(maxSum, (tort->val + hare->val));
            tort = tort->next;
            hare = hare->next;
        }

        return maxSum;
    }
};
