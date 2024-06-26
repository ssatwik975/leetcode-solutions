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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;
        int n = lists.size();
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Stitch together the lists
        for(int i = 0; i < n; i++) {
            if (lists[i] != nullptr) {
                temp->next = lists[i];
                while (temp->next) {
                    pq.push(-(temp->next->val));
                    temp = temp->next;
                }
            }
        }
        
        
        temp = dummy->next;
        
        while(temp && !pq.empty()) {
            temp->val = -pq.top();
            pq.pop();
            temp = temp->next;
        }
        

        temp = dummy->next;
        delete dummy;

        return temp;
    }
};

