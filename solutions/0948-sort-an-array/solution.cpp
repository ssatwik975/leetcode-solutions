class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i : nums){
            pq.push(-i);
        }
        vector<int> ans;
        for(int i : nums){
            ans.push_back(-(pq.top()));
            pq.pop();
        }
        return ans;
    }
};
