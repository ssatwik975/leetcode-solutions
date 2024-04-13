const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxx = INT_MIN, productfro = 1, productbac = 1;

        for(int i=0; i<n; ++i)
        {
            if(productfro == 0)
                productfro = 1;
            else if(productbac == 0)
                productbac = 1;

            productfro *= nums[i];
            productbac *= nums[n-i-1];

            maxx = max(maxx, max(productfro, productbac));
            
        }
        return maxx;
    }
};

