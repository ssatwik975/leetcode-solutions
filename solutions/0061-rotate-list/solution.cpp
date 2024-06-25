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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(!(head->next) || !k ) return head;
        ListNode* prev = head;
        ListNode* temp = head;
        ListNode* end = head;
        int size = 1;
        while(end->next){
            end = end -> next;
            size++;
        }
        k = k%size;
        int breakpoint = size-k;
        end -> next = head;
        temp = temp->next;
        breakpoint--;
        while(breakpoint--){
            temp = temp->next;
            prev = prev->next;
        }
        prev->next = NULL;
        return temp;
    }
};
