class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int t = 1; t <= 60; t++) {
            long long s = (long long)num1 - (long long)t * num2;
            if (s < 0) continue;
            if (s < t) continue;
            int ones = __builtin_popcountll(s);
            if (ones <= t) return t;
        }
        return -1;
    }
};
