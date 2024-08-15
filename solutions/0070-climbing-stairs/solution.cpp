class Solution {
public:
    int climbStairs(int n) {
        int curr = 0;
        int prev = 1;
        int penul = 0;
        for(int i = 0; i < n; i++){
            curr = prev + penul;
            penul = prev;
            prev = curr;
        }
        return curr;

    }
};
