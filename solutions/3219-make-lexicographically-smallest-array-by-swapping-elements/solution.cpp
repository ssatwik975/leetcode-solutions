class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> nums2(n);
        for (int i = 0; i < n; i++) {
            nums2[i] = {nums[i], i};
        }
        sort(nums2.begin(), nums2.end());
        vector<vector<int>> indices;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums2[i].first - nums2[i - 1].first > limit) {
                indices.push_back({});
            }
            indices.back().push_back(nums2[i].second);
        }
        vector<int> result(n);
        for (auto& index: indices) { // index is one set of sortable numbers
            vector<int> sortedIndex(index);
            sort(sortedIndex.begin(), sortedIndex.end());
            for (int j = 0; j < index.size(); j++) {
                result[sortedIndex[j]] = nums[index[j]];
            }
        }
        return result;
    }
};
