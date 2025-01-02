class Solution {
public:
    
    bool check(char c){ 
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||  c == 'u') return true; 
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v, ans;
        v.push_back(0);
        for(auto w: words){ 
            if( check(w[0]) && check(w.back()) ) v.push_back( v.back() + 1);  
            else v.push_back( v.back() );
        }
        for(auto q: queries) ans.push_back(v[q[1]+1] - v[q[0]]);
        return ans;
    }

};
