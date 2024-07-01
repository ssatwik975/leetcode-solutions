class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        for(int k : spells){
            long long required = (success + k - 1) / k;
            auto possible = lower_bound(potions.begin(), potions.end(), required);
            int val = potions.end() - possible;
            pairs.push_back(val);
        }
        return pairs;
    }
};
