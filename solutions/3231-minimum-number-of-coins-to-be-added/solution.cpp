class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int k = coins.size();
        long long int sumtillnow = 0;
        int i = 0;
        int count = 0;
        sort(coins.begin(), coins.end());
        while(sumtillnow < target){
            if(i < k && coins[i] <= sumtillnow + 1){
                sumtillnow += coins[i];
                i++;
            }
            else{
                sumtillnow += sumtillnow + 1;
                count++;
            }
        }
        return count;
        
    }
};
