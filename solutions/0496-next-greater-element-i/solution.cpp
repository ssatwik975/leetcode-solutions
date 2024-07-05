class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        unordered_map<int,int> nge;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[nums2[i]] = st.top();
            }else{
                nge[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }

        
        vector<int> ans;
        for (int k : nums1) {
            ans.push_back(nge[k]);
        }

        return ans;
    }
};

