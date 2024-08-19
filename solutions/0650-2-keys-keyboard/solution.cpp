class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        int total_operations = 0;
        for (int factor = 2; factor * factor <= n; ++factor) {
            while (n % factor == 0) {
                total_operations += factor;
                n /= factor;
            }
        }
        if (n > 1) {
            total_operations += n;
        }
        return total_operations;
    }
};
