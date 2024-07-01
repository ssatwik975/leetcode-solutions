const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;
        vector<int> mags(26, 0);
        for(char c : magazine){
            mags[c-'a']++;
        }
        for(char c: ransomNote){
            mags[c-'a']--;
            if(mags[c-'a']<0){
                return false;
            }
        }
        return true;
    }
};
