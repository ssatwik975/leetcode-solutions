class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        if(n % k != 0) return false;
        if (k == 1) return true;
        int maxim = *max_element(nums.begin(), nums.end());
        vector<int> a(maxim + 1, 0);
        for(int i = 0; i < n; i++){
            a[nums[i]]++;
        }
        int i = 1;
        while(i <= maxim){
            if(a[i] == 0) {
                i++;
                continue;
            }
            int j = 0;
            while(j < k){
                if((i + j > maxim)) return false;
                if (a[i + j] == 0) return false;
                a[i + j]--;
                j++;
            }
        }
        return true;
    }
};
