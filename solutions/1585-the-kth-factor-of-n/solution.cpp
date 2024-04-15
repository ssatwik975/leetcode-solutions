const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v;
        for(int i = 1; i <= n; ++i){
            if(n%i == 0){
                v.push_back(i);
            }
        }
        if(v.size() < k){
            return -1;
        }   
        return v[k-1];
    }
};
