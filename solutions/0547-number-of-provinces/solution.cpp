class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
        vis[node] = 1;
        for(int it : adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // Correct initialization of adjLs with n empty vectors
        vector<vector<int>> adjLs(n);
        
        // Convert matrix to adjacency list
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        // Visited array and province counter
        vector<int> vis(n, 0);
        int count = 0;

        // Run DFS for each component
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, adjLs, vis);
            }
        }

        return count;
    }
};

