const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> swag;
        int sum = 0;
        int count = 0;
        swag[0] = 1;
        int sub = 0;
        for(int i = 0; i<n; i++){   
            sum += nums[i];
            sub = sum - k;
            count += swag[sub];
            swag[sum]++;
        }
        return count;
    }
};
