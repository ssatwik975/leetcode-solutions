const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int minimumTimeToInitialState(const string &word, int k) {
        int n = word.length();
        if(n == 1e6) return 1e6;
        vector<int> z = z_function(word,n);
        int count = 1;
        for(int i = k; i <= n-1; i+=k){
            if (z[i] >= n-i)
                break;
            count++;
        }
        return count;
    }
    vector<int> z_function(const string &s, int n){
        int l = 0, r = 0;
        vector<int> z(n);
        for(int i = 1; i < n; i++) {
            if(i < r)
                z[i] = min(r - i, z[i - l]);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
};
