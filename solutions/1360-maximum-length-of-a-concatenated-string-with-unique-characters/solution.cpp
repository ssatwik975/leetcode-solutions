class Solution {
public:
        int maxLength(vector<string>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bitset<26>> m; 
        int ans=0;
        
        for(auto& s : arr)
        {
            bitset<26> bits;
            for(char c:s) bits.set(c-'a');
            int n = bits.count();
            if(n != s.size()) continue;
            
            for(int i=m.size()-1; i>=0; i--) 
            {
                auto& b = m[i];
                if((b & bits).any())
                    continue;
                ans = max<int>(ans, b.count() + n);
                m.push_back(b | bits);
            }
            m.push_back(bits);
            ans=max<int>(ans, n);
        }
        return ans;
    }
};
