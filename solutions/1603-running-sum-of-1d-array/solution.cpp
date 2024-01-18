class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> swag(n);
        swag[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            swag[i] = swag[i-1] + nums[i];
        }

        return swag;
        
    }
};
