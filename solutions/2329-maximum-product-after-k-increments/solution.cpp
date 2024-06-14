auto _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=pow(10,9)+7;
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int x=pq.top();
            pq.pop();
            x=x+1;
            pq.push(x);
            k--;
        }
        long long int ans=1;
        while(pq.size()>0){
            int x=pq.top();
            pq.pop();
            ans=(ans*x)%mod;
        }
        return ans;
    }
};

