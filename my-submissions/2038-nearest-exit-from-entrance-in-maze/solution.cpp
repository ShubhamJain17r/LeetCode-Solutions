class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();
        int x = e[0], y = e[1];

        queue<vector<int>> q;
        
        q.push({x, y, 0});
        maze[x][y] = '+';

        while (!q.empty()) {
            vector<int> temp = q.front();
            int i = temp[0];
            int j = temp[1];
            int d = temp[2];
            q.pop();

            
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && d != 0)
                return d;
            if (i > 0 && maze[i - 1][j] != '+'){
                maze[i-1][j] = '+';
                q.push({i - 1, j, d + 1});
            }
            if (j > 0 && maze[i][j - 1] != '+'){
                maze[i][j-1] = '+';
                q.push({i, j - 1, d + 1});
            }
            if (i < n - 1 && maze[i + 1][j] != '+'){
                maze[i+1][j] = '+';
                q.push({i + 1, j, d + 1});
            }
            if (j < m - 1 && maze[i][j + 1] != '+'){
                maze[i][j+1] = '+';
                q.push({i, j + 1, d + 1});
            }
        }
        return -1;
    }
};
