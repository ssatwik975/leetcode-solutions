class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
 
        vector<int> frequency(n, 0);
        for (const auto& road : roads) {
            frequency[road[0]]++;
            frequency[road[1]]++;
        }


        vector<pair<int, int>> freqNode;
        for (int i = 0; i < n; ++i) {
            freqNode.emplace_back(frequency[i], i);
        }

        sort(freqNode.begin(), freqNode.end(), greater<>());


        vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[freqNode[i].second] = n - i;
        }

 
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += importance[road[0]] + importance[road[1]];
        }

        return totalImportance;
    }
};
