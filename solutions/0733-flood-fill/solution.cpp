class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int initcolor){
        int n = image.size();
        int m = image[0].size();

        // Check for boundaries and whether the current pixel should be colored
        if(sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != initcolor) {
            return;
        }

        // Color the current pixel
        image[sr][sc] = color;

        // Explore the four possible directions
        dfs(image, sr + 1, sc, color, initcolor); // down
        dfs(image, sr - 1, sc, color, initcolor); // up
        dfs(image, sr, sc + 1, color, initcolor); // right
        dfs(image, sr, sc - 1, color, initcolor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initcolor = image[sr][sc];
        if(initcolor != color) { // Avoid infinite recursion if the new color is the same as the original color
            dfs(image, sr, sc, color, initcolor);
        }
        return image;
    }
};

