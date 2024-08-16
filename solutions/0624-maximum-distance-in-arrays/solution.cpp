class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = arrays.size();
        int indextoavoid = 0;
        int supermin = INT_MAX;
        int supermax = INT_MIN;
        int ans = 0;

        for(int i = 0; i < m; i++){
            int mini = INT_MAX;
            for(int k : arrays[i]){
                mini = min(mini, k);
            }
            if(mini < supermin){
                supermin = mini;
                indextoavoid = i;
            }
        }

        for(int i = 0; i < m; i++){
            if(i != indextoavoid){
                int maxi = INT_MIN;
                for(int k : arrays[i]){
                    maxi = max(maxi, k);
                }
                supermax = max(supermax, maxi);
            }
        }

        ans = max(ans, abs(supermax - supermin));

        supermin = INT_MAX;
        supermax = INT_MIN;

        for(int i = 0; i < m; i++){
            int maxi = INT_MIN;
            for(int k : arrays[i]){
                maxi = max(maxi, k);
            }
            if(maxi > supermax){
                supermax = maxi;
                indextoavoid = i;
            }
        }

        for(int i = 0; i < m; i++){
            if(i != indextoavoid){
                int mini = INT_MAX;
                for(int k : arrays[i]){
                    mini = min(mini, k);
                }
                supermin = min(supermin, mini);
            }
        }

        ans = max(ans, abs(supermax - supermin));
        return ans;
    }
};

