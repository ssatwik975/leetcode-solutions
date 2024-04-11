const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int low = INT_MAX;
        int max = 0;
        int cur = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < low){
                low = prices[i];
            }
            cur = prices[i] - low;
            if(max < cur){
                max = cur;
            }
        }
        return max;
    }
};
