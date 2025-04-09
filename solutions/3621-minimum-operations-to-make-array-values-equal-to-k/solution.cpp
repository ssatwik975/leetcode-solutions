class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int mini = *min_element(nums.begin(), nums.end());
            if (mini < k) return -1;
            
            unordered_set<int> st(nums.begin(), nums.end());
            return st.size() - (mini == k);
        }
    };
