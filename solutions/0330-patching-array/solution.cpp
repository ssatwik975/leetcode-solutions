class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int k = nums.size();
        long long int sumtillnow = 0;
        int i = 0;
        int count = 0;
        while(sumtillnow < n){
            if(i < k && nums[i] <= sumtillnow + 1){
                sumtillnow += nums[i];
                i++;
            }
            else{
                sumtillnow += sumtillnow + 1;
                count++;
            }
        }
        return count;
    }
};
