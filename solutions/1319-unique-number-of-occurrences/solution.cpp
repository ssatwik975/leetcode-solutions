const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int maxval = *max_element(arr.begin(), arr.end());
        int minval = *min_element(arr.begin(), arr.end());

        vector<int> hash(maxval-minval+1, 0);

        int n = arr.size();
        for (int i = 0; i < n; i++){
            hash[arr[i]-minval]++;
        }
        
        sort(hash.begin(), hash.end());

        int m = hash.size();
        for(int i = 0; i < m-1; i++){
            if(hash[i]!=0){
                if (hash[i]==hash[i+1]){
                return false;
                }
            }   
            
        }
        return true;
    }
};
