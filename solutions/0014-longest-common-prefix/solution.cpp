class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        
        int i = 0;
        sort(strs.begin(), strs.end());
        int n = strs[0].size();
        int m = strs.size();
        for(i = 0; i < n; i++){
            if(strs[0][i] == strs[m-1][i]){
                ans+= strs[0][i];
            }else{
                break;
            }
        }
        return ans;
    }
};
