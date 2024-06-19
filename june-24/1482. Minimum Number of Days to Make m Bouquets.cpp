int speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    int bookays(vector<int>& bloomDay, int day, int k, int n){
        int num = 0;
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(bloomDay[i] <= day){
                count++;
            } else {
                count = 0;
            }
            if(count == k){
                count = 0;
                num++;
            }
        }
        return num;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k > n) return -1; 

        int left = 1;
        int right = (*max_element(bloomDay.begin(), bloomDay.end()));
        int ans = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(bookays(bloomDay, mid, k, n) >= m){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
