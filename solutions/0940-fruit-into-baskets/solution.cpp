class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<int, int> types;
        for (right = 0; right < fruits.size(); right++) {
            types[fruits[right]]++;
            while (types.size() > 2) {
                types[fruits[left]]--;
                if (types[fruits[left]] == 0) {
                    types.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
