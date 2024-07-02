class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        int ans = sum;
        int i = k-1;
        int j = n;
        while(i>=0){
            sum -= cardPoints[i];
            i--;
            j--;
            sum += cardPoints[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};
