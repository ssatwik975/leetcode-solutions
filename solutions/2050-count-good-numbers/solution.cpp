class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2) { // If exp is odd, multiply the base with result
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base
            exp /= 2; // Divide the exponent by 2
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        long long result = (modExp(5, even_positions, MOD) * modExp(4, odd_positions, MOD)) % MOD;
        return (int) result;
    }
};

