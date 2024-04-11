class Solution {
public:
    void sortColors(vector<int>& nums) {
        int reds = 0;
        int whites = 0;
        int blues = 0;
        int n = nums.size();
        for(int i = 0; i< n; ++i){
            if(nums[i]==0){
                reds++;
            } else if (nums[i]==1){
                whites++;
            } else {
                blues++;
            }
        }
        for(int i = 0; i<reds; ++i){
            nums[i] = 0;
        }
        for(int i = reds; i<(reds+whites); ++i){
            nums[i] = 1;
        }
        for(int i = (reds+whites); i<(reds+whites+blues); ++i){
            nums[i] = 2;
        }
    }
};
