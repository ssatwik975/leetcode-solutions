const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();

const vector<bool> isPrime(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime[i] = false;
            }
        }
    }
    return prime;
}
const vector<bool> prime = isPrime(100);

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int first = -1, last = -1;

        for (int i = 0; i < n; i++) {
            if (prime[nums[i]]) {
                first = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (prime[nums[i]]) {
                last = i;
                break;
            }
        }

        return last - first;
    }
};

