const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstcolzero = false;
        bool firstrowzero = false;
        int colsize = matrix.size();
        int rowsize = matrix[0].size();

        for (int i = 0; i < colsize; i++) {
            if (matrix[i][0] == 0) {
                firstcolzero = true;
                break;
            } 
        }

        for (int i = 0; i < rowsize; i++) { 
            if (matrix[0][i] == 0) {
                firstrowzero = true;
                break;
            } 
        }

        for (int i = 1; i < colsize; i++) { 
            for (int j = 1; j < rowsize; j++) 

                if (matrix[i][j] == 0) {

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                }

        }

        for (int i = 1; i < colsize; i++) {
            for (int j = 1; j < rowsize; j++) 

                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
                   
        }

        if (firstcolzero) {
            for (int i = 0; i < colsize; i++) 
                matrix[i][0] = 0;
        }
        if (firstrowzero) {
            for (int i = 0; i < rowsize; i++) 
                matrix[0][i] = 0;
        }
    }

};
