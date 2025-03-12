class Solution {
public:
    int maximumCount(vector<int>& v) {
        int n = v.size();
        int firstPos = lower_bound(v.begin(),v.end(),1) - v.begin();
        int firstZero = lower_bound(v.begin(),v.end(),0) - v.begin();
        int numberOfZeros = firstPos - firstZero;
        return max(n - firstPos,firstPos - numberOfZeros);
        
    }
};
