class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3,0), cols(3, 0);
        int diag = 0, antiDiag = 0;

        int n = moves.size();

        for (int i = 0; i < n; ++i) {
            int player = (i % 2 == 0) ? 1 : -1;
            int row = moves[i][0], col = moves[i][1];

            rows[row] += player;
            cols[col] += player;
            if (row == col) diag += player;
            if (row + col == 2) antiDiag += player;

            if (abs(diag) == 3 || abs(antiDiag) == 3 || abs(rows[row]) == 3 || abs(cols[col]) == 3)
                return player == 1 ? "A" : "B"; 
        }
        return n == 9 ? "Draw" : "Pending";
    }
};
