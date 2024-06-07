class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //3
        int n = matrix[0].size(); //4
        int l = 0;
        int r = (m*n) -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[mid/n][mid%n] == target) return true;
            if(matrix[mid/n][mid%n] > target){
                r = mid + -1;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};
