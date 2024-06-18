#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
int speedup = []{ios::sync_with_stdio(0); cin.tie(0);  return(0);}();
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        
        for (int i = 0; i < n; i++) {
            fastPtr = fastPtr->next;
        }
        
        if (!fastPtr) {
            return head->next;
        }
        
        while (fastPtr->next) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        
        slowPtr->next = slowPtr->next->next;
        return head;
    }
};
