class Solution {
public:
    void dfs(vector<vector<char>>& grid, int n, int m, vector<vector<bool>>& visited, int i, int j){
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(grid, n, m, visited, i + 1, j);
        dfs(grid, n, m, visited, i, j + 1);
        dfs(grid, n, m, visited, i - 1, j);
        dfs(grid, n, m, visited, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, n, m, visited, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
