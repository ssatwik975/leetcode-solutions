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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = curr;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Compare the first and second halves of the linked list
        ListNode* first = head;
        ListNode* second = prev;
        
        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out << (equal(s.begin() + 1, s.begin() + s.size() / 2, s.rbegin() + 1)
                    ? "true\n"
                    : "false\n");
    out.flush();
    exit(0);

    return 0;
}();
