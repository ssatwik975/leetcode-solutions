const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int ans = 1;
        sort(points.begin(), points.end());
        int idx = points[0][0]; 
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] - idx > w){
                ans++; 
                idx = points[i][0]; 
            }
        }
        return ans;
    }
};
