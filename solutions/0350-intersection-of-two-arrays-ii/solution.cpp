class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int>mpp;
        int j = 0;
        int i = 0;
        for(auto x: nums1){
            mpp[x]++;
        }
        for(auto x : nums2){
            if(mpp.find(x) != mpp.end()){
                mpp[x]--;
                if(mpp[x]>=0){
                    ans.push_back(x);
                }
                
            }
        }
        return ans;
    }
};
