#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    long long dayes(vector<int>& weights, long long cap) {
        long long ans = 1; // Start with one day
        long long current_weight = 0;
        
        for(int weight : weights) {
            if (current_weight + weight > cap) {
                ans++; // Need an additional day
                current_weight = 0;
            }
            current_weight += weight;
        }
        
        return ans;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        long long left = *max_element(weights.begin(), weights.end());
        long long right = accumulate(weights.begin(), weights.end(), 0LL);
        int ans = right;
        
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if (dayes(weights, mid) <= days) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};

