int speedup = []{ios::sync_with_stdio(0); cin.tie(0);  return(0);}();

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        speedup;

        int n = nums.size();

        deque<int> minimum;
        deque<int> maximum;

        int l = 0;
        int r = 0;

        int maxsize = 0;

        while(r < n) {
            // If lower than current min, push it to the back
            // If higher, place it in the correct place and remove all elements before it, as this value would've overuled the indices before it
            while(!maximum.empty() && nums[r] >= nums[maximum.back()]) maximum.pop_back();         
            maximum.push_back(r);
            // If higher than current max, push it to the back
            // If lower, place it in the correct place and remove all elements before it, as this value would've overuled the indices before it
            while(!minimum.empty() && nums[r] <= nums[minimum.back()]) minimum.pop_back();     
            minimum.push_back(r);

            // If new min/max exceeds limit, remove prior elements in both till you reach a max/min that doesnt break limit, this works since in the queues theyre arranged as they came while making sure they dont overrule their local minimas
            while(nums[maximum.front()] - nums[minimum.front()] > limit) {
                l++;
                if(maximum.front() < l) maximum.pop_front();
                if(minimum.front() < l) minimum.pop_front();
            }
            
            maxsize = max(maxsize, r-l+1);
            r++;
        }
        

        return maxsize;
    }
};
