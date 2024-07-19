class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row_maximum_of_minimums = 0;
        for (const auto& row : matrix) {
            row_maximum_of_minimums = max(*min_element(row.begin(), row.end()), row_maximum_of_minimums);
        }

        int col_minimum_of_maximums = INT_MAX;
        for (int col_ind = 0; col_ind < cols; ++col_ind) {
            int col_maximum = 0;
            for (int row_ind = 0; row_ind < rows; ++row_ind) {
                col_maximum = max(col_maximum, matrix[row_ind][col_ind]);
            }
            col_minimum_of_maximums = min(col_maximum, col_minimum_of_maximums);
        }

        return row_maximum_of_minimums == col_minimum_of_maximums ? vector<int>{col_minimum_of_maximums} : vector<int>{};
    }
};
