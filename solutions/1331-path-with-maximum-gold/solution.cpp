class Solution {
public:
    int max = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = checkIfGridIsAllZeros(grid);
        if(count != 0) return count; 
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) traverse(grid, i, j, 0);
            }
        }
        return max;
    }

    int checkIfGridIsAllZeros(vector<vector<int>>& grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) count += grid[i][j];
                else return 0;
            }
        }
        return count;
    }

    void traverse(vector<vector<int>>& grid, int i, int j, int count){
        if(i < 0 || i >= grid.size() || j >= grid[0].size() || j < 0) return;

        if(grid[i][j] != 0){
            int tmp = grid[i][j];
            grid[i][j] = 0;
            count += tmp;

            max = std::max(max, count);

            traverse(grid, i+1, j, count);
            traverse(grid, i-1, j, count);
            traverse(grid, i, j+1, count);
            traverse(grid, i, j-1, count);

            grid[i][j] = tmp;
        }
    }
};
