class Solution {
public:
    bool traverse(vector<vector<char>>& board, string& word, unsigned int stringPos, unsigned int i, unsigned int j) { 
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;  
        if (board[i][j] == '*') return false;
        if (board[i][j] != word[stringPos]) return false;
        if (stringPos == word.size() - 1) return true;
        char ch = board[i][j];
        board[i][j] = '*';

        bool found = traverse(board, word, stringPos + 1, i + 1, j) ||
                     traverse(board, word, stringPos + 1, i, j + 1) ||
                     traverse(board, word, stringPos + 1, i - 1, j) ||
                     traverse(board, word, stringPos + 1, i, j - 1);

        board[i][j] = ch;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        unsigned int rows = board.size();
        unsigned int cols = board[0].size();

        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0] && traverse(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
