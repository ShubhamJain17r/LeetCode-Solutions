class Solution {
public:
    int backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) return 1;  // Found a valid solution
        
        int count = 0;
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;  // Main diagonal index
            int d2 = row + col;           // Anti-diagonal index
            
            // Skip if column or diagonals are occupied
            if (cols[col] || diag1[d1] || diag2[d2]) continue;
            
            // Place queen
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            // Recurse to next row
            count += backtrack(row + 1, n, cols, diag1, diag2);
            
            // Backtrack
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
        return count;
    }
    
    int totalNQueens(int n) {
        vector<bool> cols(n, false);        // Track occupied columns
        vector<bool> diag1(2 * n - 1, false); // Main diagonals (row - col + n - 1)
        vector<bool> diag2(2 * n - 1, false); // Anti-diagonals (row + col)
        
        return backtrack(0, n, cols, diag1, diag2);
    }
    
};
