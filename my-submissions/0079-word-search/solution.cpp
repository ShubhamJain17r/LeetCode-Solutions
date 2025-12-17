class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j) {
        if (idx == word.length())
            return true;
            
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
            return false;
        
        char curr = board[i][j];
        board[i][j] = '#';
        if (dfs(board, word, idx + 1, i + 1, j)) return true;

        if (dfs(board, word, idx + 1, i - 1, j)) return true;

        if (dfs(board, word, idx + 1, i, j + 1)) return true;

        if (dfs(board, word, idx + 1, i, j - 1)) return true;

        board[i][j] = curr;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};
