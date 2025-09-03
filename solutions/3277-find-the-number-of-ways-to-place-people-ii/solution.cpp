class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                // sort by y axis in descending order
                return a[1] >= b[1];
            }

            return a[0] <= b[0];
        });

        // for every lower right corner
        for (int i = n - 1; i >= 0; i--) {
            // point we are handling (lower right corner)
            int x1 = points[i][0];
            int y1 = points[i][1];

            // minimum y-coordinate greater than or equal to y1 in-between
            int middleY = INT_MAX;

            // select a valid upper left corner
            for (int j = i - 1; j >= 0; j--) {
                // point at hand
                int x1 = points[j][0];
                int y2 = points[j][1];

                if (y2 >= y1 && middleY > y2) {
                    count++;
                    middleY = min(middleY, y2);
                }
            }
        }

        return count;
    }
};
