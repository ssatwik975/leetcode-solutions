class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        bool inserted = false;

        for (const auto& interval : intervals) {
            if (interval[0] > newInterval[0] && !inserted) {
                temp.emplace_back(newInterval);
                inserted = true;
            }
            temp.emplace_back(interval);
        }

        if (!inserted) {
            temp.emplace_back(newInterval);
        }

        return merge(temp);
    }
};

