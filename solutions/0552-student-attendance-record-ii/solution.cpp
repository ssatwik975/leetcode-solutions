class Solution {
public:
    int checkRecord(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if (n == 0) return 0;
        if (n == 1) return 3;
        
        int m = 1000000007;
        int* A = new int[n + 1]();
        int* P = new int[n + 1]();
        int* L = new int[n + 1]();
        
        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        if (n > 1) A[1] = 2;
        if (n > 2) A[2] = 4;
        
        for (int i = 1; i < n; i++) {
            P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;
            
            if (i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;
            
            if (i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
        }
        
        int result = ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
        
        delete[] A;
        delete[] P;
        delete[] L;
        
        return result;
    }
};

