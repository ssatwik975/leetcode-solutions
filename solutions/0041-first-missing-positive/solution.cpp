class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n = nums.size();
        
        int oneCheck = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i]==1) oneCheck = 1;
            if(nums[i] > n || nums[i] < 1) {
                nums[i] = 1;
            }
        }

        if(!oneCheck) return 1;

        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) return i+1;
        }
        return(n+1);

    }
};
