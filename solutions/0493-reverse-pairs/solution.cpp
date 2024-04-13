const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
    vector<int> swag;
    void inc(int i) {
        for(; i < swag.size(); i += i&-i) swag[i]++;
    }
    int sum(int i) {
        int o = 0;
        for(; i; i -= i&-i) o += swag[i];
        return o;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        swag.resize( n + 1 );
        
        vector<pair<int,int>> sorted;
        for( int i = 0; i < n; i++ ) sorted.push_back( {nums[i], n - i} );
        sort( sorted.begin(), sorted.end(), []( auto &x, auto &y ) { return x.first < y.first; } );
        
        for( int i = 0, j = 0; i < n; i++ )
        {
            while( j < n && 2L*sorted[j].first < sorted[i].first ) inc( sorted[j++].second );
            count += sum( sorted[i].second - 1 );
        }
        return count;
    }
};
