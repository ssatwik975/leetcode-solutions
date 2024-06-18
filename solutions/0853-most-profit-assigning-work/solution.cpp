auto speedup = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
#pragma gcc optimization ("O3, unroll-loops, no-stack-protector, fast-math, inline, unsafe-math-optimizations");
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // sort the jobs based on profit in descending order
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        // sort(jobs.begin(), jobs.end(), [](pair<int, int>& a, pair<int, int>& b) {
        //     return a.second > b.second;
        // });
        // map the worker to the maximum profit he can get
        vector<int> maxProfit(100001, 0);
        for (int i = 0; i < jobs.size(); i++) {
            maxProfit[jobs[i].first] = max(maxProfit[jobs[i].first], jobs[i].second);
        }
        
        for (int i = 1; i < maxProfit.size(); i++) {
            maxProfit[i] = max(maxProfit[i], maxProfit[i - 1]);
        }
        // find the maximum profit that can be achieved
        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            ans += maxProfit[worker[i]];
        }
        return ans;
    }
};
