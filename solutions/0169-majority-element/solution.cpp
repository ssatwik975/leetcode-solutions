const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int ele = nums[0], cnt = 0;

        for(auto it: nums)
        {
            if(it != ele)
            {
                cnt--;

                if(cnt == 0)
                {
                    ele = it;
                    cnt = 1;
                }
            }
            else cnt++;
        }
        return ele;
    }
};
