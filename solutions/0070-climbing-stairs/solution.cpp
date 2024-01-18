class Solution {
public:
    int climbStairs(int n) {

        if (n==0 || n == 1){
            return 1;
        }

        vector <int> swag(n+1);
        swag[0] = 1;
        swag[1] = 1;

        for (int i = 2; i <= n; i++){
            swag[i] = swag[i-1]+swag[i-2];
        }
        
        int ans = swag[n];

        return ans;

    }
};
