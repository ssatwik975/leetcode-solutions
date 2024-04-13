const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRow;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }
            
            result.push_back(currentRow);
            prevRow = currentRow;
        }
        
        return result;
    }
};

