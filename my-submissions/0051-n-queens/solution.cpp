class Solution {
public:
    bool isSafe(int n, vector<string>& board, int row, int col){
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q') return false;
        return true;
    }
    void solveNQueensHelper(int n, vector<string>& board, vector<vector<string>>& solutions, int row){
        if (row == n){
            solutions.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i){
            if (isSafe(n, board, row, i)){
                board[row][i] = 'Q';
                solveNQueensHelper(n, board, solutions, row + 1);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(n, board, solutions, 0);
        return solutions;
    }
};
