class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseena = -1;
        int lastseenb = -1;
        int lastseenc = -1;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='a'){
                lastseena = i;
            }else if(s[i]=='b'){
                lastseenb = i;
            }else{
                lastseenc = i;
            }
            if(lastseena >= 0 && lastseenb >= 0 && lastseenc >= 0){
                ans += (min({lastseena, lastseenb, lastseenc}) + 1);
            }
        }
        return ans;
    }
};
