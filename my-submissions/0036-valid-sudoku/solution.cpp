class Solution {
public:
    bool validSudokuHelper(int idx, vector<vector<char>>& board) {
        vector<bool> rowSeen(9, false);
        vector<bool> colSeen(9, false);
        vector<bool> boxSeen(9, false);

        int boxRow = (idx / 3) * 3;
        int boxCol = (idx % 3) * 3;

        for (int i = 0; i < 9; i++) {
            if (board[idx][i] != '.') {
                int num = board[idx][i] - '1';
                if (rowSeen[num]) return false;
                rowSeen[num] = true;
            }

            if (board[i][idx] != '.') {
                int num = board[i][idx] - '1';
                if (colSeen[num]) return false;
                colSeen[num] = true;
            }

            char b = board[boxRow + i / 3][boxCol + i % 3];
            if (b != '.') {
                int num = b - '1';
                if (boxSeen[num]) return false;
                boxSeen[num] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!validSudokuHelper(i, board))
                return false;
        }
        return true;
    }
};

