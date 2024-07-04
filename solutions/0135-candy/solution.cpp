int speedup = [] {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> ans(n, 1);

//         for (int i = 1; i < n; i++) {
//             if (ratings[i] > ratings[i - 1]) {
//                 ans[i] = ans[i - 1] + 1;
//             }
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             if (ratings[i] > ratings[i + 1]) {
//                 ans[i] = max(ans[i], ans[i + 1] + 1);
//             }
//         }

//         int sum = 0;
//         for (int i : ans) {
//             sum += i;
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;
        int n = ratings.size();
        int i = 1;
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                down++;
                i++;
            }
            if (down > peak) {
                sum += down - peak;
            }
        }
        return sum;
    }
};
