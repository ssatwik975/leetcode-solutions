class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(const char &c : s){
            if(ans.size() == 0){
                ans.push_back(c);
            }else if(ans.back() == c){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};
