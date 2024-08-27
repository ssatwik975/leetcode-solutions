class Solution {
public:
    double ans = 0;
    double mn = 1e-5;

    // Recursive function to find the maximum probability
    void f(int start, int end, vector<bool> &vis, vector<pair<int, double>> adj[], double sum) {
        // If the current sum is less than or equal to the minimum threshold, return
        if (sum <= mn) return;

        // If we have reached the destination node, update the answer if the current sum is greater
        if (start == end) {
            ans = max(ans, sum);
            return;
        }

        vis[start] = true;
        for (auto node : adj[start]) {
            int child = node.first;
            double p = node.second;

            // If the child node is not visited and the current sum times the probability is greater than the current answer,
            // recursively explore the child node
            if (vis[child] == false && sum * p >= ans) {
                f(child, end, vis, adj, sum * p);
            }
        }
        vis[start] = false;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
     {
        // Create an adjacency list to represent the graph
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) 
        {
            adj[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            adj[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        // Initialize the visited array
        vector<bool> vis(n, false);

        // Call the recursive function to find the maximum probability
        f(start, end, vis, adj, 1);
        return ans;
    }
};

