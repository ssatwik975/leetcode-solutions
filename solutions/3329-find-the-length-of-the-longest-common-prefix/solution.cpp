


class Solution {
public:
    class Node{
        public:
            Node* digits[10];   
    };
    void add(Node* head, int num){
        string t = to_string(num);
        Node* ptr = head;
        for(auto c: t){
            if(!ptr->digits[c - '0']) ptr->digits[c - '0'] = new Node();
            ptr = ptr->digits[c-'0'];
        }
    }
    int check(Node* head, int num){
        Node* ptr = head;
        string t = to_string(num);
        int len = 0;
        for(auto c: t){
            if(ptr->digits[c - '0']) len++;
            else break;
            ptr = ptr->digits[c-'0'];
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Node* head = new Node();
        for(auto num: arr1) add(head, num);
        for(auto num: arr2) ans = max(ans, check(head, num));
        return ans;
    }
};
