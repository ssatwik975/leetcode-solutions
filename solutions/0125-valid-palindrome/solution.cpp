class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a = 0;
        int b = s.size()-1;

        while(a<=b){
            if(!isalnum(s[a])){
                a++;
                continue;
            }
            if(!isalnum(s[b])){
                b--;
                continue;
            }
            if(tolower(s[a]) != tolower(s[b])) return false;
            else{
                a++;
                b--;
            }
        }
        return true;
    }
};
