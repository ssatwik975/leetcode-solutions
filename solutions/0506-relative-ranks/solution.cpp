class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
  vector<short> idx(nums.size());
  vector<string> res(nums.size());
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&nums](int i, int j) { return nums[i] > nums[j]; });
  for (auto i = 0; i < nums.size(); ++i)
    res[idx[i]] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i + 1);
  return res;
}
};
