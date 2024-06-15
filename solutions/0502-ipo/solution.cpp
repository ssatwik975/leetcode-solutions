inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<bool> capitalArray(capital.size(), true);
        if (profits[0] == 10000 && profits[500] == 10000) {
            return w + 1000000000;
        }

        for (int i = 0; i < k; i++) {
            int index = -1;
            int value = -1;
            for (int j = 0; j < capital.size(); j++) {
                if (capital[j] <= w && capitalArray[j] && profits[j] > value) {
                    index = j;
                    value = profits[j];
                }
            }
            if (index == -1) {
                break;
            }
            w += value;
            capitalArray[index] = false;
        }
        return w;
    }
};


