class Solution {
public:
    int mySqrt(int x) {
        if(x < 1){
            return 0;
        }
        if (x < 4) return 1;
        int left = 2;
        int right = x/2;
        int ans;
        while(left <= right){
            long long mid = (left + right)/2;
            if(mid * mid <= x){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
        return ans;
    }
};
