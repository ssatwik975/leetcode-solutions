class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '('){
                if(opened > 0){
                    res += c;
                }
                opened++;
            }else{
                if(opened > 1){
                   res += c; 
                }
                opened--;
            }
        }
        return res;
    }
};
