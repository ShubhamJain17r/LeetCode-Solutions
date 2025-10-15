class Solution {
public:
    bool  isValid(vector<vector<char>>& board, int row, int col, char digit){
        for (int i = 0; i < 9; ++i){
            if (board[row][i] == digit) return false;
            if (board[i][col] == digit) return false;
        }
        int r = row / 3 * 3, c = col / 3 * 3;
        for (int i = r; i < r + 3; ++i){
            for (int j = c; j < c + 3; ++j){
                if (board[i][j] == digit) return false;
            }
        }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>>& board, int row, int col){
        if (row == 9) return true;
        if (col == 9) 
            return solveSudokuHelper(board, row + 1, 0);

        if (board[row][col] != '.') {
            return solveSudokuHelper(board, row, col + 1);
        }

        for (char digit = '1'; digit <= '9'; ++digit){
            if (isValid(board, row, col, digit)){
                board[row][col] = digit;
                if (solveSudokuHelper(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
};
