const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char &c:num){
            while(ans.size() && ans.back()>c && k){
                ans.pop_back();
                k--;
            }
            if(ans.size() || c!= '0'){
                ans.push_back(c);
            }
        }
        while(ans.size() && k--){
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
    }
};
