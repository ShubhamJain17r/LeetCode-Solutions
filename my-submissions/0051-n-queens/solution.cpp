class Solution {
public:
    bool isValid(vector<string> &board, int row, int col) {
        // row check
        for (int r = 0; r < row; ++r)
            if (board[r][col] == 'Q') return false;
        
        // row check;
        for (int c = 0; c < col; ++c) 
            if (board[row][c] == 'Q') return false;

        // top left side diag
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) 
            if (board[r][c] == 'Q') return false;

        // top right side diag
        for (int r = row - 1, c = col + 1; r >= 0 && c < board.size(); r--, c++)
            if (board[r][c] == 'Q') return false;
        return true;
    }

    void nQueens(int n, int row, vector<string> &board, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!isValid(board, row, i)) continue;
            board[row][i] = 'Q';
            nQueens(n, row + 1, board, ans);
            board[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueens(n, 0, board, ans);
        return ans;
    }
};
