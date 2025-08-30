class Solution {
public:
    bool validRow(vector<vector<char>>& board, int row, int col, char digit){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i] == digit)
                return false;
        }
        return true;
    }
    bool validCol(vector<vector<char>>& board, int row, int col, char digit){
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col] == digit)
                return false;
        }
        return true;
    }
    bool validGrid(vector<vector<char>>& board, int row, int col, char digit){
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++)
            if((i!=row || j!=col) && board[i][j] == digit)
                return false;
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')
                if(!(validRow(board,i,j,board[i][j]) && validCol(board,i,j,board[i][j]) && validGrid(board,i,j,board[i][j])))
                    return false;
            }
        }
        return true;
    }
};
