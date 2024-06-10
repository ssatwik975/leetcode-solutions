class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> freq(101, 0);

        for (int h : heights) {
            freq[h]++;
        }

        int ans = 0; 
        int currentHeight = 0; 

        for (int i = 0; i < n; i++) {
            
            while (freq[currentHeight] == 0) {
                currentHeight++;
            }
            
            if (heights[i] != currentHeight) {
                ans++;
            }
            
            freq[currentHeight]--;
        }

        return ans; 
    }
};

