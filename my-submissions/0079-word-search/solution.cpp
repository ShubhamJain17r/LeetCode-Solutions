class Solution {
public:
    bool wordSearch(vector<vector<char>>& board, string word, int m, int n,int row, int col,int idx){
        if (idx == word.length()){
            return true;
        }
        char c = board[row][col];
        board[row][col] = '#';
        if (row + 1 < m && board[row + 1][col] == word[idx]){
            if(wordSearch(board, word, m, n, row + 1, col, idx + 1)){
                return true;
            }
        }
        if (row - 1 >= 0 && board[row - 1][col] == word[idx]){
            if(wordSearch(board, word, m, n, row - 1, col, idx + 1)){
                return true;
            }
        }
        if (col + 1 < n && board[row][col + 1] == word[idx]){
            if(wordSearch(board, word, m, n, row, col + 1, idx + 1)){
                return true;
            }
        }
        if (col - 1 >= 0 && board[row][col - 1] == word[idx]){
            if(wordSearch(board, word, m, n, row, col - 1, idx + 1)){
                return true;
            }
        }
        board[row][col] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == word[0] && wordSearch(board, word, m, n, i, j, 1)){
                    return true;
                }
            }
        }
        return false;
    }
};
