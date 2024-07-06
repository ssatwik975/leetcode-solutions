class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>leftsmaller(n);
        vector<int>rightsmaller(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftsmaller[i] = 0;
            }else{
                leftsmaller[i] = st.top() + 1;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightsmaller[i] = n-1;
            }else{
                rightsmaller[i] = st.top()-1;
            }
            st.push(i);
        }

        int maxA = INT_MIN;
        for(int i = 0; i < n; i++){
            maxA = max(maxA, (heights[i]*(rightsmaller[i]-leftsmaller[i] + 1)));
        }
        return maxA;
    }
};
