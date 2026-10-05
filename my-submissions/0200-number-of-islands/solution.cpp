class Solution {
public:
    void travel(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        travel(i + 1, j, grid);
        travel(i - 1, j, grid);
        travel(i, j + 1, grid);
        travel(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    travel(i, j, grid);
                }
            }
        }
        return ans;
    }
};
