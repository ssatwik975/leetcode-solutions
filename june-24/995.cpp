#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void flip(vector<int>& nums, int i, int k){
        for(int j = i; j < i+k; j++){
            nums[j] = 1-nums[j];
        }
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n-k; i++){
            if(nums[i]==1){
                continue;
            }else{
                flip(nums,i,k);
                ans++;
            }
        }
        //checking if nums is fully 1
        for(int i = n-k; i < n; i++){
            if(nums[i]==0){
                return -1;
            }
        }
        //return ans if true else return -1
        return ans;

    }
};