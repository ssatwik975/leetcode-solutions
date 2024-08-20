class Solution {
public:
    // Alex and Lee play optimally and each one takes stones only from the FIRST X
    // remaining piles! So they cannot change and take for example the last x piles.
    // We use DP for this problem beacuse we have many different combinations to cover!
    
    int stoneGameII(vector<int>& piles) {
        if (piles.empty()) return 0;
        // Handle the edge case where there's only one pile
        if (piles.size() == 1) return piles[0];
        // First we calculate the sum of all piles from the end to the begging 
        // in order to be able to retrieve quickly how many stones a player has
        // if for example is in position i of piles and can take 3 piles.
        // The answer is sums[i] - (the number of stones the other player will
        // take with max 6 piles (2*M))
        std::vector<int> sums(piles.size(), 0);
        sums[piles.size()-1] = piles[piles.size()-1];
        for (int i = piles.size()-2; i >= 0; i--) {
            sums[i] = sums[i+1]+piles[i];
        }
        // We create the memorization vector where dp[i][j] is the optimal choice  
        // in the i position of piles with max 2*j piles. 
        std::vector<std::vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
        helper(piles, dp, sums, 0, 1);
        // Alex starts first and so he is at position 0 of piles and he beggins with 
        // max 2*1 options.
        return dp[0][1];
    }
    int helper(vector<int>& piles, vector<vector<int>>& dp, vector<int>& sums, int i, int M) {
        if (i == piles.size()) return 0; // We reach the end of piles.
        if (2*M >= piles.size()-i) return sums[i];  // If 2*M is equal of more of the rest of the
                                                    // piles then the player takes them all because
                                                    // every player plays optimally.
        if (dp[i][M]) return dp[i][M];  // We might have been in this stage before with the same or 
                                        // the other player and so we already know the optimal
                                        // choice from this position.
        
        int min = INT_MAX;
        // We calculate the more stones the next player will get for every choice of M we will make
        // and we choose the minimun of those!
        for (int j = 1; j <= 2*M; j++) {
            min = std::min(min, helper(piles, dp, sums, i+j, std::max(j, M)));
        }
        // The stones we will get are those in the sums position we stand minus the ones the next
        // player will get!
        return dp[i][M] = sums[i]-min;
    }
};
