class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        int a = 0;
        int b = 0;
        while(a<s.length()){
            if(t[b] == s[a]){
                b++;
                a++;
            }else{
                a++;
            }
        }
        ans = t.length() - b;
        return ans;
    }
};
