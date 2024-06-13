class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++){
            ans = ans ^ i;
            ans = ans ^ nums[i];
        }
        return ans;

        // int size = nums.size();
        // int total = size * (size+1) / 2;

        // int sum = 0;

        // for(int i=0; i < size; ++i ){
        //     sum += nums[i];
        // }

        // return total - sum;
        
    }
};
