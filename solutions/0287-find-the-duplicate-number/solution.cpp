static const bool Init = []() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

inline bool is_digit(char c) { return (c >= '0' && c <= '9'); }

std::vector<int> parse_input_data_string(const std::string& s) {
    std::vector<int> input_data_1D;
    const int N = s.size();
    int left = 0;
    while (left < N) {
        if (!is_digit(s[left])) {
            ++left;
            continue;
        }
        int right = left;
        int value = 0;
        while (right < N && is_digit(s[right])) {
            value = value * 10 + (s[right] - '0');
            ++right;
        }
        input_data_1D.push_back(value);
        left = right;
    }
    return input_data_1D;
}

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};
