class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;
        while(left<=right){
            maxwater = max(maxwater, ((right - left) * (min(height[left],height[right]))));
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxwater;
    }
};
