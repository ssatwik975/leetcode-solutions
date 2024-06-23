class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        int ans = 0;
        for(int i = 0; i<heights.size();i++){
            expected.push_back(heights[i]);
        }
        sort(heights.begin(),heights.end());
        for(int i = 0;i<heights.size();i++){
            if(expected[i]!=heights[i]){
                ans++;
            }
        }
        return ans;
    }
};
