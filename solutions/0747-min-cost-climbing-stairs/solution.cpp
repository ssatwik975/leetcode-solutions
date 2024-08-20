class Solution {
public:
    int here(vector<int>& cost, int n, vector<int>& dp){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1]; // Base case for the first step
        
        if(dp[n] != -1) return dp[n];

        int onestep = cost[n] + here(cost, n-1, dp);
        int twostep = cost[n] + here(cost, n-2, dp);
        
        return dp[n] = min(onestep, twostep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        
        // We need to calculate the minimum cost to get to either of the last two steps,
        // since you can step directly onto the top from there.
        return min(here(cost, n-1, dp), here(cost, n-2, dp));
    }
};

