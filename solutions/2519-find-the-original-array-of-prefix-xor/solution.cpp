class Solution {
public:
    vector<int> findArray(vector<int>& prefix) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> arr = {prefix[0]};
        for(int i = 1 ; i < prefix.size() ; i++)
        {
            arr.push_back(prefix[i] ^ prefix[i-1]);
        }
        return arr;
    }
};
