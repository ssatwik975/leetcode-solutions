
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        ListNode *hare = head;
        ListNode *tort = head;

        while(hare && hare->next){
            hare = hare->next->next;
            tort = tort->next;
            if(hare == tort) return true;
        }
        return false;
    }
};
