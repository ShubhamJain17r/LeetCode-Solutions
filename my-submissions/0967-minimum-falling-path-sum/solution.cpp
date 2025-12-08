class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {    
        int n = grid.size();

        vector<int> next(n, 0);
        for (int j = 0; j < n; ++j) {
            next[j] = grid[n-1][j];
        }
        for (int i = n-2;  i >= 0; --i) {
            vector<int> curr(n);
            for (int j = 0; j < n; ++j) {
                int best = next[j]; // down
                if (j > 0) best = min(best, next[j-1]); // down-left
                if (j < n-1) best = min(best, next[j+1]); // down-right

                curr[j] = grid[i][j] + best;
            }
            next = curr;
        }


        return *min_element(next.begin(), next.end());
    }
};
