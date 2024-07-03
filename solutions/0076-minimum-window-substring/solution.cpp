class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int>freq;
        for(char c : t){
            freq[c]++;
        }

        int count = 0;
        int left = 0;
        int right = 0;
        int start = -1;
        int minlen = INT_MAX;

        while(right < s.size()){
            if(freq[s[right]]>0){
                count++;
            }
            freq[s[right]]--;

            while(count == t.size()){
                if(minlen > (right-left + 1)){
                    minlen = (right - left) + 1;
                    start = left;
                }

                freq[s[left]]++;
                if(freq[s[left]] > 0){
                    count--;
                }

                left++;
            }

            right++;
        }

        if(start == -1){
            return "";
        }

        return s.substr(start, minlen);
    }
};
