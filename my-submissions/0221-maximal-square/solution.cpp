class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        int maxi = 0;

        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j] - '0';
            maxi = max(maxi, prev[j]);
        }

        // Fill remaining dp cells
        for (int i = 1; i < m; i++) {
            curr[0] = matrix[i][0] -  '0';
            maxi = max(maxi, curr[0]);
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                    maxi = max(maxi, curr[j]);
                }
                else
                    curr[j] = 0;
            }
            prev = curr;
        }

        return maxi * maxi; // area
    }
};

