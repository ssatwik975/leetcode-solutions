class Solution {
public:
    long long minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long difference = abs(goal - sum);
        long long left = difference % limit;
        return (difference / limit) + (left ? 1 : 0);
    }
};
