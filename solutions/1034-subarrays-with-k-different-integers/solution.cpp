#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int func(vector<int>&nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0;
        int right = 0;
        unordered_map <int, int> freq;
        int count = 0;

        while(right < nums.size()){
            freq[nums[right]]++;

            while(freq.size() > goal){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right-left) + 1;
            right++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return func(nums, k) - func(nums, k-1);
    }
};
