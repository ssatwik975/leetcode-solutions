class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long countgood = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int start = 0;
        long long pairs = 0;

        for (int end = 0; end < n; ++end) {

            pairs += freq[nums[end]];

            freq[nums[end]]++;

            while (pairs >= k) {
                countgood += (n - end);

                freq[nums[start]]--;
                pairs -= freq[nums[start]];

                start++;
            }
        }

        return countgood;
    }
};
