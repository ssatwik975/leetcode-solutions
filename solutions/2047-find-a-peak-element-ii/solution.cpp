class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0, endCol = mat[0].size() - 1;
        
        while(startCol <= endCol) {
            int midCol = startCol + (endCol - startCol)/2;
            
            int maxRow = 0;
            for(int r = 0; r < mat.size(); r++) {
                if(mat[r][midCol] > mat[maxRow][midCol]) {
                    maxRow = r;
                }
            }
            
            int currElement = mat[maxRow][midCol];
            int leftElement = midCol == 0 ? -1 : mat[maxRow][midCol - 1];
            int rightElement = midCol == mat[0].size() - 1 ? -1 : mat[maxRow][midCol + 1];
            
            if(currElement > leftElement and currElement > rightElement) {
                // currElement is peak element
                return { maxRow, midCol };
            }
            else if(leftElement > currElement) {
                endCol = midCol - 1; 
            }
            else {
                startCol = midCol + 1;
            }
        }
        return { -1, -1 };
    }
};
