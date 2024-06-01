int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int sofar = n-1;
        for(int i = n-2; i >= 0; i--){
            if(sofar<=i+nums[i]){
                sofar = i;
            }
        }
        return sofar<=0;

    }
};
