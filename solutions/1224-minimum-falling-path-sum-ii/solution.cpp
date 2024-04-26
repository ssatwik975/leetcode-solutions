const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int fm = 0, sm = 0, pos = -1;
        for (auto i = 0; i < arr.size(); ++i) {
            auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
            for (auto j = 0; j < arr[i].size(); ++j) {
                auto mn = j != pos ? fm : sm;
                if (arr[i][j] + mn < fm2) {
                    sm2 = fm2;
                    fm2 = arr[i][j] + mn;
                    pos2 = j;
                } else sm2 = min(sm2, arr[i][j] + mn);
            }
            fm = fm2, sm = sm2, pos = pos2;
        }
    return fm;
    }
};
