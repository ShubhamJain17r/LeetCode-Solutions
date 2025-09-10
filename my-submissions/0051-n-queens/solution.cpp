class Solution {
public:
    bool isSafe(vector<string>& board, int n, int row, int col){
        for (int i = 0; i<row; ++i){
            if (board[i][col] == 'Q') return false;
        }
        for (int i = 0; i<col; ++i){
            if (board[row][i] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j){
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<string>& board, int n, vector<vector<string>>& ans, int row){
        if (row == n){
            ans.push_back(board);
            return;
        }

        for (int col = 0; col<n; ++col){
            if (isSafe(board, n, row, col)){
                board[row][col] = 'Q';
                helper(board, n, ans, row+1);
                board[row][col] =  '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        helper(board, n, res, 0);
        return res;
    }
};
