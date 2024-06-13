const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = 0;
        int ele2 = 0;
        int c1 = 0;
        int c2 = 0;
        for (const int& num : nums) {
            if (c1 == 0 && num != ele2) {
                ++c1;
                ele1 = num;
            } else if (c2 == 0 && num != ele1) {
                ++c2;
                ele2 = num;
            } else if (ele1 == num) {
                ++c1;
            } else if (ele2 == num) {
                ++c2;
            } else {
                --c1;
                --c2;
            }
        }
        vector<int> ls;
        c1 = 0;
        c2 = 0;
        for (const int& num : nums) {
            if (num == ele1)
                c1++;
            else if (num == ele2)
                c2++;
        }
        int mini = (int)(n / 3) + 1;
        if (c1 >= mini)
            ls.emplace_back(ele1);
        if (c2 >= mini)
            ls.emplace_back(ele2);

        return ls;
    }
};

