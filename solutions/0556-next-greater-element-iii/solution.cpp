const auto init = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return nullptr;
}();
class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        vector<int> nums;
        for (char c : num) {
            nums.push_back(c - '0');
        }
        int k = nums.size();
        int down = -1;

        for (int i = k - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                down = i;
                break;
            }
        }

        if (down == -1) {
            return -1;
        }

        for (int i = k - 1; i > down; i--) {
            if (nums[i] > nums[down]) {
                swap(nums[i], nums[down]);
                break;
            }
        }

        reverse(nums.begin() + down + 1, nums.end());

        string answer;
        for (int digit : nums) {
            answer += to_string(digit);
        }


        if (stoll(answer) > INT_MAX) {
            return -1;
        }

        return static_cast<int>(stoll(answer));
    }
};
