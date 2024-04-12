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
const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while(head != NULL && head->val == val){
            head = head -> next;
        }

        if(head == NULL)
            return {};

        ListNode*prev = head;
        ListNode*ptr = head -> next;
        
        while(ptr != NULL){
            if(ptr->val == val){
                prev -> next = ptr -> next;
                ptr = ptr -> next;
            }
            else{
                prev = ptr;
                ptr = ptr -> next;
            }
        }

        return head;
    }
};
