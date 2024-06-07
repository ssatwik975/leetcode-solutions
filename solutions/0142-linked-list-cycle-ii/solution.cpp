/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* tort = head;
        ListNode* hare = head;
        ListNode* ans = head;
        while(hare && hare->next){
            hare = hare->next->next;       
            tort = tort->next;
            if(tort == hare){
                while(ans != tort){
                    ans = ans->next;
                    tort = tort->next;
                }
                return ans;
            }
        }
        return nullptr;      
    }
};
