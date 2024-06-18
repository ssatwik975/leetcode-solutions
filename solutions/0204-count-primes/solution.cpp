#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
int speedup = []{ios::sync_with_stdio(0); cin.tie(0);  return(0);}();
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        for (long long i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (long long j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
            }
        }

        return count;
    }
};
