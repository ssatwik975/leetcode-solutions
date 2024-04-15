const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    
    vector<bool> isPrime(int n){
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(prime[i]){
                for(int j=i*i; j<=n; j+=i){
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    int maximumPrimeDifference(vector<int>& nums) {
       int n = nums.size();
        vector<bool> prime = isPrime(100);
        int first = -1, last = -1;

        for(int i=0; i<n; i++)
        {
            if(prime[nums[i]]){
                if(first == -1){
                    first = i;
                    break;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            if(prime[nums[i]]){
                if(last == -1){
                    last = i;
                    break;
                }
            }
        }

        if(first == -1){
            return 0;
        }

        return last - first;

    }
};

