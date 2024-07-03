class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        for(char c : s){
            if(c == '('){
                count++;
            }else if (c == ')'){
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
