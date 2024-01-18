class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rows = accounts.size();
        int cols = accounts[0].size();
        int richest = 0;

        for (int i = 0; i < rows; ++i) {
            const vector<int>& currentAccount = accounts[i];
            int sum = 0;

            for (int j = 0; j < cols; ++j) {
                sum += currentAccount[j];
            }

            if (richest < sum) {
                richest = sum;
            }
        }

        return richest;
    }
};

